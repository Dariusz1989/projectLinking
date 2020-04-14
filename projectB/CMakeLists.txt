
set(INCL_DIRS
        "${PROJECT_SOURCE_DIR}"
        #insert desired Qt include dirs here
        )

#insert desired Qt lib names here
set(THIRD_PARTY
        projA
        )

MakeLibTarget(projB STATIC src/extendedTreeView.cpp "${INCL_DIRS}" "${THIRD_PARTY}")
MakeTestExeTarget(projB main.cpp)