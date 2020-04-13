
set(INCL_DIRS 
	"${PROJECT_SOURCE_DIR}"
	#insert desired Qt include dirs here
)
set(THIRD_PARTY
	core
	#insert desired Qt lib names here
)

MakeLibTarget(projA STATIC src/treeView.cpp "${INCL_DIRS}" "${THIRD_PARTY}")
MakeTestExeTarget(projA main.cpp)



