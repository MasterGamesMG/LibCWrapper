# Add source to this project's executable.
add_executable(LibCWrapper 
	"main.cpp"
	"../../../LibCWrapper/LibCWrapper.cpp" 
	"../../../LibCWrapper/LibCWrapper.h"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LibCWrapper PROPERTY CXX_STANDARD 20)
endif()