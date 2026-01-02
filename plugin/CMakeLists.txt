INCLUDE(BuildPlugin)

BUILD_PLUGIN(
  lrcscroll
    LRCScroll.cpp
    LRCScrollView.cpp
    LRCScrollKeyFilter.cpp
    VerticalMarquee.cpp
    TimestampEditor.cpp
 
  MOCFILES
    LRCScroll.h
    LRCScrollView.h
    LRCScrollKeyFilter.h
    VerticalMarquee.h
    TimestampEditor.h
 
  EMBEDDED_RESOURCES
    logo.svg
)