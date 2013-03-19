#include <postgresql/libpq-fe.h>
#include <stdio.h>
#include <stdlib.h>

#define DB_NAME 		"projet_p2p"
#define DB_USER 		"admin"
#define DB_PASSWORD 	"projet2013_RX"


/* code taken from : http://www.shlomifish.org/lecture/PostgreSQL-Lecture/c_program.html */

void exit_nicely(PGconn * conn)
{
    PQfinish(conn);
    exit(1);
}

int main()
{
	PGconn *conn = NULL;
	PGresult * res = NULL;
	
	int i=0, rec_count=0;
	
	/* Connect to database */
	
	conn = PQsetdbLogin(NULL, NULL, NULL, NULL, DB_NAME, DB_USER, DB_PASSWORD);
                                   
    if (PQstatus(conn) == CONNECTION_BAD)
    {
        fprintf(stderr, "Connection to database \"%s\" failed.\n", DB_NAME);
        fprintf(stderr, "%s", PQerrorMessage(conn));
        exit_nicely(conn);
    }

	/* */
	res = PQexec(conn, "select * from registered_users");

	if (res == NULL || PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        fprintf(stderr, "SELECT command did not return tuples properly\n");
        PQclear(res);
        exit_nicely(conn);
    }
    
    /* iterate through res : PQgetvalue(res, line, column) */
	rec_count = PQntuples(res);
	
	for(i = 0; i < rec_count; i = i + 1)
	{
		printf("%s %s\n", PQgetvalue(res, i, 1), PQgetvalue(res, i, 2));
	}


	/* End of connection */
	PQclear(res);
	PQfinish(conn);
	return 0;
}
