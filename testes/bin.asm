SECTION TEXT
INPUT OLD_DATA
LOAD OLD_DATA
L1: DIV DOIS
STORE  NEW_DATA
MUL DOIS
STORE TMP_DATA
load old_data 
   SUB TMP_DATA
STORE TMP_DATA
OUTPUT         TMP_DATA    ;espacos a mais
COPY NEW_DATA , OLD_DATA
LOAD OLD_DATA        
JMPP L1;comentario no final da linha
; comentario alone
;linha vazia
STOP
SECTION DATA
DOIS: CONST 2
OLD_DATA: SPACE
NEW_DATA: SPACE
TMP_DATA: SPACE