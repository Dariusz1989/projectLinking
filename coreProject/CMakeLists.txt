
set(SOURCES 
	icLib/testClass.cpp
	icLib/icEntity/entity.cpp
)
set(INCL_DIRS 
	"${PROJECT_SOURCE_DIR}"
	#insert desired Qt include dirs here
)
set(THIRD_PARTY
	extra
	#insert desired Qt lib names here
		opengl32.lib
		Qt5::Widgets
		Qt5::Core
		Qt5::Gui
		Qt5::Network
		Qt5::Concurrent
		Qt5::Test
)

MakeLibTarget(core STATIC "${SOURCES}" "${INCL_DIRS}" "${THIRD_PARTY}")
MakeTestExeTarget(core main.cpp)