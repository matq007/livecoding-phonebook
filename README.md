# livecoding-phonebook

This is an example implementation of command-live based phonebook. Request was posted in [livecoding spreadsheet] 
(https://docs.google.com/spreadsheets/d/1SJ5YEgBLIApfw7rUGWOKHoJipNHY-5LssE2nT-gVa3I/edit).

To run application type:
    
    mkdir build
    cd build
    cmake ..

I also implemented some dummy unit tests as an example. You can run unit tests simply by 
running command:
    
    ./unitTest

## About

By default application will create XML File (phonebook.xml) where all contacts, will be stored.
You can also run application with path parameter to xml file. The file has to have below 
structure, or it will not work!
 
    <phoneBook>
        <ID_MAX>0</ID_MAX>
        <contacts/>
    </phoneBook>

Application start with printing menu options:
    
    MENU:
    [1] Help
    [2] Show Phonebook
    [3] Show/Find contact
    [4] Add contact
    [5] Edit contact
    [6] Delete contact
    [7] Quit

Saving will be always performed when exiting application, so don't forget to use choice 7, otherwise your data
will not be stored! 

### TODO:

- verify XML File structure
- user already exists method
- edit get() in PhoneBookCollection
- more unit tests 