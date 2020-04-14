
set(INCL_DIRS
        "${PROJECT_SOURCE_DIR}"
        #insert desired Qt include dirs here


        )

#insert desired Qt lib names here
set(THIRD_PARTY
        core
        )

MakeLibTarget(projA STATIC src/treeView.cpp "${INCL_DIRS}" "${THIRD_PARTY}")
MakeTestExeTarget(projA main.cpp)



