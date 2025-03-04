myContacts1317931: contactsA2.o createContactsA2.o readContactsA2.o searchContactsA2.o include/givenA2.h
	gcc -Wall -std=c99 contactsA2.o createContactsA2.o readContactsA2.o searchContactsA2.o -o bin/myContacts1317931 -lm
contactsA2.o: src/contactsA2.c include/givenA2.h
	gcc -Wall -std=c99 -c src/contactsA2.c -lm
createContactsA2.o: src/createContactsA2.c include/givenA2.h
	gcc -Wall -std=c99 -c src/createContactsA2.c -lm
readContactsA2.o: src/readContactsA2.c include/givenA2.h
	gcc -Wall -std=c99 -c src/readContactsA2.c -lm
searchContactsA2.o: src/searchContactsA2.c include/givenA2.h
	gcc -Wall -std=c99 -c src/searchContactsA2.c -lm
clean:
	rm src/*.o *.db bin/myContacts1317931

