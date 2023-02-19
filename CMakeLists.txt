cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME "Dawnbreaker")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

#SET(FREEGLUT_REPLACE_GLUT ON CACHE BOOL "" FORCE)

IF(APPLE)
    add_definitions(-DGL_SILENCE_DEPRECATION)
ENDIF()

add_subdirectory(
  "${CMAKE_CURRENT_LIST_DIR}/third_party/SOIL/"
  "${CMAKE_CURRENT_BINARY_DIR}/SOIL"
  EXCLUDE_FROM_ALL
)

IF (APPLE)
ELSE()
  add_subdirectory(
    "${CMAKE_CURRENT_LIST_DIR}/third_party/freeglut/"
    "${CMAKE_CURRENT_BINARY_DIR}/freeglut"
    EXCLUDE_FROM_ALL
  )
  set(FREEGLUT_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/third_party/freeglut/include")
ENDIF()


add_library(
  ProvidedFramework
  STATIC
  src/ProvidedFramework/ObjectBase.h
  src/ProvidedFramework/ObjectBase.cpp
  src/ProvidedFramework/WorldBase.h
  src/ProvidedFramework/WorldBase.cpp
  src/ProvidedFramework/GameManager.h
  src/ProvidedFramework/GameManager.cpp
  src/ProvidedFramework/SpriteManager.h
  src/ProvidedFramework/SpriteManager.cpp
  src/utils.h
)

IF (APPLE)
  target_link_libraries(
    ProvidedFramework
    SOIL
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework GLUT"
  )

  target_include_directories(
    ProvidedFramework
    PUBLIC
    src/
    src/ProvidedFramework/
  )
ELSE()
  target_link_libraries(
    ProvidedFramework
    freeglut
    SOIL
  )

  target_include_directories(
    ProvidedFramework
    PUBLIC 
    ${FREEGLUT_INCLUDE_DIR}
    src/
    src/ProvidedFramework/
  )
ENDIF()
add_library(
    Decoration
    STATIC
    src/PartForYou/Decoration/Star.h
    src/PartForYou/Decoration/Star.cpp
    src/PartForYou/Decoration/Explosion.h
    src/PartForYou/Decoration/Explosion.cpp
    src/PartForYou/Decoration/Decoration.h
    src/PartForYou/Decoration/Decoration.cpp
)

add_library(
    Enemy
    STATIC
    src/PartForYou/Enemy/Enemy.h
    src/PartForYou/Enemy/Enemy.cpp
    src/PartForYou/Enemy/Alpha.h
    src/PartForYou/Enemy/Alpha.cpp
    src/PartForYou/Enemy/Sigma.h
    src/PartForYou/Enemy/Sigma.cpp
    src/PartForYou/Enemy/Omega.h
    src/PartForYou/Enemy/Omega.cpp
)

add_library(
    FlyingObjects
    STATIC
    src/PartForYou/FlyingObjects/Meteor.h
    src/PartForYou/FlyingObjects/Meteor.cpp
    src/PartForYou/FlyingObjects/BlueBullet.h
    src/PartForYou/FlyingObjects/BlueBullet.cpp
    src/PartForYou/FlyingObjects/RedBullet.h
    src/PartForYou/FlyingObjects/RedBullet.cpp
    src/PartForYou/FlyingObjects/FlyingObjects.h
    src/PartForYou/FlyingObjects/FlyingObjects.cpp
)

add_library(
    Props
    STATIC
    src/PartForYou/Props/Props.h
    src/PartForYou/Props/Props.cpp
    src/PartForYou/Props/HPRestore.h
    src/PartForYou/Props/HPRestore.cpp
    src/PartForYou/Props/PowerUp.h
    src/PartForYou/Props/PowerUp.cpp
    src/PartForYou/Props/MeteorProp.h
    src/PartForYou/Props/MeteorProp.cpp
)

add_library(
  PartForYou
  STATIC
  src/PartForYou/GameWorld.h
  src/PartForYou/GameWorld.cpp
  src/PartForYou/GameObjects.h
  src/PartForYou/GameObjects.cpp
  src/PartForYou/_DawnBreaker.h
  src/PartForYou/_DawnBreaker.cpp
  src/utils.h
)
target_link_libraries(
  Enemy
  Decoration
)

target_link_libraries(
  Enemy
  FlyingObjects
)

target_link_libraries(
  FlyingObjects
  Enemy
)

target_link_libraries(
  Enemy
  Props 
)


target_link_libraries(
  Enemy
  PartForYou
)

target_link_libraries(
  PartForYou
  Enemy
)

target_link_libraries(
  FlyingObjects
  PartForYou
)
target_link_libraries(
  PartForYou
  FlyingObjects
)

target_link_libraries(
  Decoration
  PartForYou
)
target_link_libraries(
  PartForYou
  Decoration
)
target_link_libraries(
  Props
  PartForYou
)
target_link_libraries(
  PartForYou
  Props
)

target_link_libraries(
  PartForYou
  ProvidedFramework
)

target_include_directories(
  PartForYou
  PUBLIC 
  src/
  src/ProvidedFramework/
  src/PartForYou/
)

target_include_directories(
    Enemy
    PUBLIC
    src/PartForYou
    src/PartForYou/Enemy
)

target_include_directories(
    FlyingObjects
    PUBLIC
    src/PartForYou
    src/PartForYou/FlyingObjects
)

target_include_directories(
    Decoration
    PUBLIC
    src/PartForYou
    src/PartForYou/Decoration
)

target_include_directories(
    Props
    PUBLIC
    src/PartForYou
    src/PartForYou/Props
)

add_executable(
  ${PROJECT_NAME}
  src/main.cpp
)

target_link_libraries(
  ${PROJECT_NAME}
  ProvidedFramework
  PartForYou
)

target_include_directories(
  ${PROJECT_NAME} 
  PUBLIC 
  src/
  src/ProvidedFramework/
  src/PartForYou/
)
