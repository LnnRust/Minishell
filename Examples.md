```sh
< Makefile cat > test1 | ls | wc -c | cat > test2
echo $USER
cd .. | cat < Makefile | grep .c | wc -l > test1 > test22 > test3 >>test4 < test11
echo '"$USER"'
echo "'$USER'"
<< EOF cat > test1 | << EOF1 << EOF2 << EOF3 cat >> test2
```

Leaks possibles :

- Leak en faisant un CTRL + C dans un heredoc.

Bugs chelous :

- Si tu crées un fork tu stoppes d'utiliser les built-ins du minishell, donc tu utilises les built-ins de Bash.

# Contre-mesures

## Variables d'environnement

env invalide.

Tester avec des commandes comme:
```sh
env -i /bin/valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./minishell
```
