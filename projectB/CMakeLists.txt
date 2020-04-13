
set(INCL_DIRS 
	"${PROJECT_SOURCE_DIR}"
	#insert desired Qt include dirs here
)
set(THIRD_PARTY
	projA
	#insert desired Qt lib names here
)

MakeLibTarget(projB STATIC src/extendedTreeView.cpp "${INCL_DIRS}" "${THIRD_PARTY}")
MakeTestExeTarget(projB main.cpp)