cmake_minimum_required (VERSION 2.6)
project(YGELib)

FIND_PACKAGE( SDL )

FIND_PACKAGE( OpenAL )

FIND_PACKAGE( OpenGL )

FIND_PATH(ODE_INCLUDE_DIR ode/ode.h
  /usr/include
  /usr/local/include
)
FIND_LIBRARY(ODE_LIBRARY
  NAMES ode
  PATHS
   /usr/lib
   /usr/local/lib
)

SET( src_files
#  src/YGEGame.cpp
  src/GameHUD.cpp
  src/GameStateIngame.cpp
  src/GameLevel.cpp
  src/GameStateSplashscreen.cpp
  src/GameRocket.cpp
  src/Menu.cpp
  src/GameGyrocopter.cpp
  src/GameBall.cpp
#  src/stdafx.cpp
  src/GameManager.cpp
  src/GameStateMainmenu.cpp
)


FIND_PATH( YGE_INCLUDE_DIR YGEGraphicsCore.cpp
  ../YGELib_src/src
)

FIND_LIBRARY( YGE_LIBRARY 
  NAMES yge
)

INCLUDE_DIRECTORIES(
  ${SDL_INCLUDE_DIR}
  ${OPENAL_INCLUDE_DIR}
  ${YGE_INCLUDE_DIR}
  ./src
  .
)

LINK_LIBRARIES(
  ${YGE_LIBRARY}
  SDL
  SDL_ttf
  GL
  GLU
  glee
  ode
  alut
)

ADD_EXECUTABLE( gyrowings ${src_files} )
