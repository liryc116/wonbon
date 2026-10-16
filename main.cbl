IDENTIFICATION DIVISION.
PROGRAM-ID. WONBON.

DATA DIVISION.
FILE SECTION.
WORKING-STORAGE SECTION.
       01 DATA-SOURCE.
           03 PROVIDER PIC X(64) VALUE
              "query.yahooapis.com".
           03 FILLER PIX X(256) VALUE
              'q=select * from yahoo.finance.quotes where symbol in ("YHOO","AAPL","GOOG","MSFT")'
              & '&format=json&env=http://datatables.org/alltables.env'.

       01 DATA-OUT.
           03 BUFFER PIC X(1024).

PROCEDURE DIVISION.

MAIN-PROCEDURE.

**********This is a comment in Cobol***************

           CALL "https_get" USING BY CONTENT URL,
                                  BY REFERENCE BUFFER
            DISPLAY 'Returned value =' RETURN-CODE
            DISPLAY 'Retrieved data :' BUFFER
DISPLAY NUM1.
DISPLAY MESSAGE.
STOP RUN.
END PROGRAM WONBON.
