## RESUMINDO O OUTPUT DE FDS DO VALGIND

> --track-fds.

-  **3 FDs não padrão (103, 39, 38):** Herdados do processo pai (VS Code), relacionados ao funcionamento interno do VS Code. Seu minishell não os abriu e não é responsável por eles.

- **3 FDs padrão (0, 1, 2):** São stdin, stdout, stderr. Eles também são fornecidos pelo ambiente que executa seu minishell e são essenciais para a operação do seu shell. É normal e correto que estejam abertos na saída.

O Valgrind lista o total (6) e depois especifica os 3 padrão (3 std) e os outros que não são padrão (os 3 herdados que ele detalha). Não há nenhum FD que seu minishell tenha aberto e esquecido de fechar, de acordo com este relatório.