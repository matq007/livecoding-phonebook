add_library(app_lib
            app.h
            Contact.h
            PhoneBook.h
            PhoneBookCollection.h
            PhoneBookParser.h
            ../include/tinyxml2/tinyxml2.h

            app.cpp
            Contact.cpp
            PhoneBook.cpp
            PhoneBookCollection.cpp
            PhoneBookParser.cpp
            ../include/tinyxml2/tinyxml2.cpp
            )

target_include_directories(app_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} app_lib)