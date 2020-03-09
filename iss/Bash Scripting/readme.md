## 1.

	Keeps track of your favourite songs.


    Command line argument is given

    1st argument can be "add" or "select" or "list" or "delete" or "edit"

    for add:-
      User can give any no. of fields.
      Only song name is essential. Other fields are not mandatory.
      Format of argument:- "field:information to be filled in field"
                    For ex:- ./1.sh "add" "singer-name:Justin" "song_name:Sorry" "writer_name:xyz".
      User can give any name for any field but for song name, name of field should be "song_name:xyz".
      Fields can be given in any order.
    
    for delete:- 
      Only one argument which is "id no." 
      for ex:- ./1.sh "delete" "2"
    
    for edit:-:
      First argument is id no.
      Then any  field you want to change or add. Format is same as for add.
      For ex:- ./1.sh "edit" "1" "song_name:abc" "genre:xyz"
    
    for list:-
      no arguments taken.
      for ex:- ./1.sh "list"

    for select:-
      You can give any field acc to which you want to filter and can filter it more
      For ex:- ./1.sh "select" "singer_name:xyz" "genre:abc" "writer:def"
      it will first select rows with singer_name=xyz and then from it, rows with genre=abc get selected ,then from it,rows with writer=def get selected and shown on terminal.

##  2.   

		Script to count no of times string occurs in source of web page


        two command line arguments are taken:- 
                                          the string to look up for, 
                                          the URL of the website you want to look at. 
##  3.

		Reminds you to take break after every 25 min.


        one command line argument is taken:-
                                          number of iterations (work + break)
        3d.sh - to install dependency

##  4.

		Keep track of all reminders and notifies you


        4.sh -to install all dependencies

    for add:-
         first 3 arguments are compulsory i.e "date" "time" "body" "frequency"(optional)
        format of date ="YY-MM-DD"
        format of time = "hr:min"(24 hr format)
        for ex:- ./add4.sh "19-03-20" "23:11" "abcd" "2"(optional)

    for delete:-
         one argument i.e id
        for ex:- ./delete4.sh "2"

    for list:-
         one optional argument is taken 
        it can be date or body
        format "date:YY-MM-DD" or "body:abc"
        for ex:- ./list4.sh 
        for ex:- ./list4.sh "date:19-03-20"
        for ex:- ./list4.sh "body:abc"

    for edit:-
         4 mandatory arguments:-id,date,time,body,frequency(optional)
        for ex:- ./edit4.sh "2" "19-03-20" "23:45" "abc" "2"(optional)

##  5.
		Print last modified time of file in pwd


        NO command line arguments are taken.

##  6.

		Sort movies acc. to imdb ratings.

		
        two command line arguments are taken:-
        <Path to the movies_input file> <Path to the directory which would contain movie files>
