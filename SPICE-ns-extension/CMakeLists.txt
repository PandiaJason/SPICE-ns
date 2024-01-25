check_include_file_cxx(stdint.h HAVE_STDINT_H)
if(HAVE_STDINT_H)
    add_definitions(-DHAVE_STDINT_H)
endif()

set(examples_as_tests_sources)
if(${ENABLE_EXAMPLES})
    set(examples_as_tests_sources
        #test/SPICE-ns-examples-test-suite.cc
        )
endif()

build_lib(
    LIBNAME SPICE-ns
    SOURCE_FILES model/SPICE-ns.cc
		 model/mobility/spice-mobility-model.cc
                 helper/SPICE-ns-helper.cc
    HEADER_FILES model/SPICE-ns.h
		 model/mobility/spice-mobility-model.h
                 helper/SPICE-ns-helper.h
    LIBRARIES_TO_LINK ${libcore}
    TEST_SOURCES test/SPICE-ns-test-suite.cc
                 ${examples_as_tests_sources}
)

