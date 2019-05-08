# Banco de Dados

## Tutoriais

Em nossas aulas, usaremos o MySQL para os exercícios. Sugiro utilizar o MariaDB, que é um fork do MySQL com alguns recursos a mais e performance melhorada, além de ser open-source.

### Instalação do MariaDB - Windows

1. Acesse o site [Downloads - MariaDB.org](https://downloads.mariadb.org/) 

![Downloads - MariaDB.org](imagens/tutorial_mariadb_win_01.jpg)

2. Escolha a versão estável (no nosso exemplo, a 10.3.14) e clique no botão verde "Download 10.3.14 Stable Now!"

![Downloads - MariaDB.org](imagens/tutorial_mariadb_win_02.jpg)

3. Localize o link de download para a plataforma Windows x64 (mariadb-10.3.14-win64.msi), baixe o arquivo e execute. Caso você utilize um Windows 32 bits, o link é o mariadb-10.3.14-win32.msi.

![Downloads - MariaDB.org](imagens/tutorial_mariadb_win_03.jpg)

4. O processo de instalação é simples:
        
        a. Aceite os termos da licença.
![Downloads - MariaDB.org](imagens/tutorial_mariadb_win_04.jpg)

        b. Selecione todas as opções para instalação.
![Downloads - MariaDB.org](imagens/tutorial_mariadb_win_05.jpg)

        c. Defina a senha para o usuário root, habilite o acesso remoto e defina o encoding padrão para UTF-8.
![Downloads - MariaDB.org](imagens/tutorial_mariadb_win_06.jpg)

        d. Mantenha as configurações de serviço, networking e engine como padrão. O nome do serviço é MySQL para que as ferramentas de acesso ao banco (HeidiSQL, DBeaver, MySQL Workbench não tenham problemas para conectar).
![Downloads - MariaDB.org](imagens/tutorial_mariadb_win_07.jpg)    

        e. Não é necessário habilitar o plugin de feedback.
![Downloads - MariaDB.org](imagens/tutorial_mariadb_win_08.jpg)        

        f. Proceda a instalação (é necessário ter um usuário administrador do Windows, pois a configuração de serviço não pode ser feita por um usuário comum).
![Downloads - MariaDB.org](imagens/tutorial_mariadb_win_09.jpg)
![Downloads - MariaDB.org](imagens/tutorial_mariadb_win_10.jpg)
![Downloads - MariaDB.org](imagens/tutorial_mariadb_win_11.jpg)