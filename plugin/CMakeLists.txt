INCLUDE(BuildPlugin)

BUILD_PLUGIN(
  LRCScroll
    LRCScroll.cpp
    LRCScrollView.cpp
    TimestampEditor.cpp
 
  MOCFILES
    LRCScroll.h
    LRCScrollView.h
    TimestampEditor.h
 
  EMBEDDED_RESOURCES
    logo.svg
)