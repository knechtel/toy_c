#include <stdio.h>
#include <mysql/mysql.h>

int main() {
    MYSQL *con;

    con = mysql_init(NULL);

    if (con == NULL) {
        fprintf(stderr, "Erro ao inicializar MySQL\n");
        return 1;
    }

    if (mysql_real_connect(
            con,
            "127.0.0.1",
            "root",
            "123",
            "teste_c",
            3306,
            NULL,
            0) == NULL) {

        fprintf(stderr, "Erro de conexão: %s\n", mysql_error(con));
        mysql_close(con);
        return 1;
    }

    printf("Conectado ao MySQL!\n");

    if (mysql_query(
            con,
            "INSERT INTO pessoas (nome, idade) VALUES ('Maiquel', 40)"
        )) {

        fprintf(stderr, "Erro ao inserir: %s\n", mysql_error(con));
        mysql_close(con);
        return 1;
    }

    printf("Pessoa salva com sucesso!\n");

    mysql_close(con);

    return 0;
}
