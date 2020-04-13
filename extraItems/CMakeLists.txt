
set(INCL_DIRS 
	"${PROJECT_SOURCE_DIR}"
	#insert desired Qt include dirs here
)
set(THIRD_PARTY 
	#insert desired Qt lib names here
)

MakeLibTarget(extra STATIC someEnums.cpp "${INCL_DIRS}" "${THIRD_PARTY}")
MakeTestExeTarget(extra main.cpp)