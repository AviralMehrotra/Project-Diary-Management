

# Personal Diary Management System

This program is a simple Personal Diary Management System implemented in C language. It allows the user to add new records, search for existing records, and display all saved records.

## Features
- Adding new records: The user can add a new record to the diary by entering the date, time, place, duration of stay and a note.
- Searching for records: The user can search for an existing record by entering the date.
- Displaying all saved records: The program displays all saved records in a tabular format.

## How to run the program
1. Download and install a C compiler like Dev-C++ or Code::Blocks.
2. Copy the source code to a new project.
3. Compile and run the program.

## Functions
- `ins_first()`: Inserts a new record at the beginning of the linked list.
- `display_dir(int item)`: Displays all saved records in a tabular format. If `item` is 0, it displays all saved records. Otherwise, it displays a message that no contacts are present.
- `search_data(int srch)`: Searches for an existing record by entering the date.

## Future improvements
- Add the option to edit existing records.
- Improve the user interface and make it more user-friendly.
- Add the option to export the data to a file.

## Note
This code is not optimized for large datasets and should only be used for small personal diaries.
