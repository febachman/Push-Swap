#!/usr/bin/env bash

PS="${PS:-./push_swap}"

if [ -n "$CHECKER" ]; then
	CHECKER="$CHECKER"
elif [ -x "./checker" ]; then
	CHECKER="./checker"
elif [ -x "./checker_linux" ]; then
	CHECKER="./checker_linux"
else
	echo "ERRO: não achei ./checker nem ./checker_linux"
	exit 1
fi

PASS=0
FAIL=0
TOTAL=0

GREEN="\033[32m"
RED="\033[31m"
YELLOW="\033[33m"
BLUE="\033[34m"
RESET="\033[0m"

TMP_DIR=".push_swap_test_tmp"
LAST_ARGS=".push_swap_last_fail_args.txt"
LAST_OPS=".push_swap_last_fail_ops.txt"
LAST_CMD=".push_swap_last_fail_command.txt"

mkdir -p "$TMP_DIR"

short_text()
{
	local TEXT="$1"
	local LIMIT="$2"

	if [ ${#TEXT} -gt "$LIMIT" ]; then
		echo "${TEXT:0:$LIMIT} ... [cortado]"
	else
		echo "$TEXT"
	fi
}

arg_count()
{
	local ARG="$1"

	if [ -z "$ARG" ]; then
		echo 0
	else
		echo "$ARG" | wc -w | tr -d ' '
	fi
}

print_title()
{
	echo
	echo -e "${BLUE}========== $1 ==========${RESET}"
}

ok()
{
	echo -e "${GREEN}[OK]${RESET} $1"
	PASS=$((PASS + 1))
	TOTAL=$((TOTAL + 1))
}

fail_detail()
{
	local NAME="$1"
	local EXPECTED="$2"
	local GOT="$3"
	local COMMAND="$4"
	local ARG="$5"
	local FLAGS="$6"
	local OUT_FILE="$7"
	local ERR_FILE="$8"
	local OPS_FILE="$9"

	local SHORT_COMMAND
	local SHORT_ARG
	local OUT_LINES
	local ERR_LINES
	local OPS_LINES

	SHORT_COMMAND=$(short_text "$COMMAND" 180)
	SHORT_ARG=$(short_text "$ARG" 180)

	echo
	echo -e "${RED}[FAIL]${RESET} $NAME"

	echo -e "${YELLOW}COMANDO:${RESET}"
	echo "  $SHORT_COMMAND"

	if [ -n "$FLAGS" ]; then
		echo -e "${YELLOW}FLAGS:${RESET}"
		echo "  $FLAGS"
	fi

	if [ -n "$ARG" ]; then
		echo -e "${YELLOW}ARGUMENTOS:${RESET}"
		echo "  quantidade: $(arg_count "$ARG")"
		echo "  exemplo: $SHORT_ARG"
		printf "%s\n" "$ARG" > "$LAST_ARGS"
		echo "  argumentos completos salvos em: $LAST_ARGS"
	fi

	printf "%s\n" "$COMMAND" > "$LAST_CMD"
	echo -e "${YELLOW}COMANDO COMPLETO:${RESET}"
	echo "  salvo em: $LAST_CMD"

	echo -e "${YELLOW}ESPERADO:${RESET}"
	echo "  $EXPECTED"

	echo -e "${YELLOW}SAIU:${RESET}"
	echo "  $GOT"

	if [ -n "$OUT_FILE" ] && [ -f "$OUT_FILE" ]; then
		OUT_LINES=$(wc -l < "$OUT_FILE" | tr -d ' ')
		echo -e "${YELLOW}STDOUT:${RESET}"
		if [ "$OUT_LINES" -eq 0 ]; then
			echo "  <vazio>"
		else
			echo "  teve $OUT_LINES linha(s)"
			echo "  primeira linha:"
			head -n 1 "$OUT_FILE" | sed 's/^/    /'
		fi
	fi

	if [ -n "$ERR_FILE" ] && [ -f "$ERR_FILE" ]; then
		ERR_LINES=$(wc -l < "$ERR_FILE" | tr -d ' ')
		echo -e "${YELLOW}STDERR:${RESET}"
		if [ "$ERR_LINES" -eq 0 ]; then
			echo "  <vazio>"
		else
			echo "  teve $ERR_LINES linha(s)"
			echo "  primeira linha:"
			head -n 1 "$ERR_FILE" | sed 's/^/    /'
		fi
	fi

	if [ -n "$OPS_FILE" ] && [ -f "$OPS_FILE" ]; then
		OPS_LINES=$(wc -l < "$OPS_FILE" | tr -d ' ')
		cp "$OPS_FILE" "$LAST_OPS" 2>/dev/null

		echo -e "${YELLOW}OPERAÇÕES:${RESET}"
		echo "  foram geradas $OPS_LINES operação(ões)"
		echo "  lista escondida para não poluir a tela"
		echo "  operações completas salvas em: $LAST_OPS"
	fi

	echo -e "${YELLOW}DICA:${RESET}"
	echo "  Corrige primeiro este erro. Não tenta resolver todos ao mesmo tempo."

	echo

	FAIL=$((FAIL + 1))
	TOTAL=$((TOTAL + 1))
}

count_ops()
{
	local FILE="$1"

	if [ -s "$FILE" ]; then
		wc -l < "$FILE" | tr -d ' '
	else
		echo 0
	fi
}

run_sort_test()
{
	local NAME="$1"
	local FLAGS="$2"
	local ARG="$3"

	local OUT="$TMP_DIR/push_swap_out.txt"
	local ERR="$TMP_DIR/push_swap_err.txt"
	local CHK_OUT="$TMP_DIR/checker_out.txt"
	local CHK_ERR="$TMP_DIR/checker_err.txt"
	local INVALID="$TMP_DIR/invalid_ops.txt"

	local PS_EXIT
	local CHK_RES
	local CHK_ERR_RES
	local OPS
	local N

	: > "$OUT"
	: > "$ERR"
	: > "$CHK_OUT"
	: > "$CHK_ERR"
	: > "$INVALID"

	eval "$PS $FLAGS $ARG" > "$OUT" 2> "$ERR"
	PS_EXIT=$?

	eval "$CHECKER $ARG" < "$OUT" > "$CHK_OUT" 2> "$CHK_ERR"
	CHK_RES=$(cat "$CHK_OUT")
	CHK_ERR_RES=$(cat "$CHK_ERR")
	OPS=$(count_ops "$OUT")
	N=$(arg_count "$ARG")

	if [ "$PS_EXIT" -ne 0 ]; then
		fail_detail \
			"$NAME" \
			"push_swap deve terminar sem erro e gerar operações válidas" \
			"push_swap terminou com exit code $PS_EXIT" \
			"$PS $FLAGS $ARG | $CHECKER $ARG" \
			"$ARG" \
			"$FLAGS" \
			"$OUT" \
			"$ERR" \
			"$OUT"
		return
	fi

	if [ -s "$ERR" ]; then
		fail_detail \
			"$NAME" \
			"push_swap não deve escrever nada no stderr com entrada válida" \
			"push_swap escreveu no stderr" \
			"$PS $FLAGS $ARG" \
			"$ARG" \
			"$FLAGS" \
			"$OUT" \
			"$ERR" \
			"$OUT"
		return
	fi

	if grep -Ev '^(sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr)$' "$OUT" > "$INVALID"; then
		fail_detail \
			"$NAME" \
			"stdout deve conter apenas operações válidas, uma por linha" \
			"existem linhas inválidas no stdout do push_swap" \
			"$PS $FLAGS $ARG" \
			"$ARG" \
			"$FLAGS" \
			"$INVALID" \
			"$ERR" \
			"$OUT"
		return
	fi

	if [ "$CHK_RES" != "OK" ]; then
		fail_detail \
			"$NAME" \
			"checker deve imprimir OK, porque as operações precisam ordenar a pilha" \
			"checker imprimiu '$CHK_RES'" \
			"$PS $FLAGS $ARG | $CHECKER $ARG" \
			"$ARG" \
			"$FLAGS" \
			"$CHK_OUT" \
			"$CHK_ERR" \
			"$OUT"
		return
	fi

	if [ -n "$CHK_ERR_RES" ]; then
		fail_detail \
			"$NAME" \
			"checker não deve escrever no stderr com operações válidas" \
			"checker escreveu no stderr" \
			"$PS $FLAGS $ARG | $CHECKER $ARG" \
			"$ARG" \
			"$FLAGS" \
			"$CHK_OUT" \
			"$CHK_ERR" \
			"$OUT"
		return
	fi

	ok "$NAME | n=$N | ops=$OPS | flags=${FLAGS:-default}"
}

run_strategy_tests()
{
	local NAME="$1"
	local ARG="$2"

	run_sort_test "$NAME default" "" "$ARG"
	run_sort_test "$NAME simple" "--simple" "$ARG"
	run_sort_test "$NAME medium" "--medium" "$ARG"
	run_sort_test "$NAME complex" "--complex" "$ARG"
	run_sort_test "$NAME adaptive" "--adaptive" "$ARG"
}

run_checker_test()
{
	local NAME="$1"
	local ARG="$2"
	local OPS_TEXT="$3"
	local EXPECT="$4"

	local OUT="$TMP_DIR/checker_direct_out.txt"
	local ERR="$TMP_DIR/checker_direct_err.txt"
	local OPS_FILE="$TMP_DIR/checker_direct_ops.txt"
	local RES
	local ERR_RES

	: > "$OUT"
	: > "$ERR"
	printf "%b" "$OPS_TEXT" > "$OPS_FILE"

	eval "$CHECKER $ARG" < "$OPS_FILE" > "$OUT" 2> "$ERR"

	RES=$(cat "$OUT")
	ERR_RES=$(cat "$ERR")

	if [ "$RES" != "$EXPECT" ]; then
		fail_detail \
			"$NAME" \
			"checker deve imprimir exatamente '$EXPECT'" \
			"checker imprimiu '$RES'" \
			"$CHECKER $ARG" \
			"$ARG" \
			"" \
			"$OUT" \
			"$ERR" \
			"$OPS_FILE"
		return
	fi

	if [ -n "$ERR_RES" ]; then
		fail_detail \
			"$NAME" \
			"checker não deve escrever nada no stderr neste caso" \
			"checker escreveu no stderr" \
			"$CHECKER $ARG" \
			"$ARG" \
			"" \
			"$OUT" \
			"$ERR" \
			"$OPS_FILE"
		return
	fi

	ok "$NAME | esperado=$EXPECT"
}

run_push_swap_error_test()
{
	local NAME="$1"
	local COMMAND="$2"

	local OUT="$TMP_DIR/push_swap_error_out.txt"
	local ERR="$TMP_DIR/push_swap_error_err.txt"
	local OUT_MSG
	local ERR_MSG

	: > "$OUT"
	: > "$ERR"

	bash -c "$PS $COMMAND" > "$OUT" 2> "$ERR"

	OUT_MSG=$(cat "$OUT")
	ERR_MSG=$(cat "$ERR")

	if [ -z "$OUT_MSG" ] && echo "$ERR_MSG" | grep -qx "Error"; then
		ok "$NAME | Error correto"
	else
		fail_detail \
			"$NAME" \
			"stdout vazio e stderr contendo exatamente: Error" \
			"stdout='$(short_text "$OUT_MSG" 80)' stderr='$(short_text "$ERR_MSG" 80)'" \
			"$PS $COMMAND" \
			"$COMMAND" \
			"" \
			"$OUT" \
			"$ERR" \
			""
	fi
}

run_checker_error_test()
{
	local NAME="$1"
	local ARG="$2"
	local OPS_TEXT="$3"

	local OUT="$TMP_DIR/checker_error_out.txt"
	local ERR="$TMP_DIR/checker_error_err.txt"
	local OPS_FILE="$TMP_DIR/checker_error_ops.txt"
	local OUT_MSG
	local ERR_MSG

	: > "$OUT"
	: > "$ERR"
	printf "%b" "$OPS_TEXT" > "$OPS_FILE"

	bash -c "$CHECKER $ARG" < "$OPS_FILE" > "$OUT" 2> "$ERR"

	OUT_MSG=$(cat "$OUT")
	ERR_MSG=$(cat "$ERR")

	if echo "$ERR_MSG" | grep -qx "Error"; then
		ok "$NAME | Error correto"
	else
		fail_detail \
			"$NAME" \
			"stderr contendo exatamente: Error" \
			"stdout='$(short_text "$OUT_MSG" 80)' stderr='$(short_text "$ERR_MSG" 80)'" \
			"$CHECKER $ARG" \
			"$ARG" \
			"" \
			"$OUT" \
			"$ERR" \
			"$OPS_FILE"
	fi
}

run_no_arg_test()
{
	local OUT="$TMP_DIR/no_arg_out.txt"
	local ERR="$TMP_DIR/no_arg_err.txt"

	: > "$OUT"
	: > "$ERR"

	$PS > "$OUT" 2> "$ERR"

	if [ ! -s "$OUT" ] && [ ! -s "$ERR" ]; then
		ok "push_swap sem argumentos não imprime nada"
	else
		fail_detail \
			"push_swap sem argumentos" \
			"stdout vazio e stderr vazio" \
			"programa imprimiu alguma coisa" \
			"$PS" \
			"" \
			"" \
			"$OUT" \
			"$ERR" \
			""
	fi

	: > "$OUT"
	: > "$ERR"

	$CHECKER > "$OUT" 2> "$ERR"

	if [ ! -s "$OUT" ] && [ ! -s "$ERR" ]; then
		ok "checker sem argumentos não imprime nada"
	else
		fail_detail \
			"checker sem argumentos" \
			"stdout vazio e stderr vazio" \
			"programa imprimiu alguma coisa" \
			"$CHECKER" \
			"" \
			"" \
			"$OUT" \
			"$ERR" \
			""
	fi
}

run_random_tests()
{
	local SIZE="$1"
	local REPEAT="$2"
	local i
	local ARG
	local OUT="$TMP_DIR/perf_out.txt"
	local ERR="$TMP_DIR/perf_err.txt"
	local OPS

	i=1
	while [ "$i" -le "$REPEAT" ]; do
		ARG=$(shuf -i 0-100000 -n "$SIZE" | tr '\n' ' ')

		run_sort_test "random size=$SIZE test=$i" "" "$ARG"

		: > "$OUT"
		: > "$ERR"

		$PS $ARG > "$OUT" 2> "$ERR"
		OPS=$(count_ops "$OUT")

		if [ "$SIZE" -eq 100 ]; then
			if [ "$OPS" -lt 2000 ]; then
				ok "performance 100 números | ops=$OPS | limite < 2000"
			else
				fail_detail \
					"performance 100 números" \
					"menos de 2000 operações" \
					"$OPS operações" \
					"$PS [100 números] | wc -l" \
					"$ARG" \
					"" \
					"$OUT" \
					"$ERR" \
					"$OUT"
			fi
		fi

		if [ "$SIZE" -eq 500 ]; then
			if [ "$OPS" -lt 12000 ]; then
				ok "performance 500 números | ops=$OPS | limite < 12000"
			else
				fail_detail \
					"performance 500 números" \
					"menos de 12000 operações" \
					"$OPS operações" \
					"$PS [500 números] | wc -l" \
					"$ARG" \
					"" \
					"$OUT" \
					"$ERR" \
					"$OUT"
			fi
		fi

		i=$((i + 1))
	done
}

run_bench_test()
{
	local NAME="$1"
	local FLAGS="$2"
	local ARG="$3"

	local OUT="$TMP_DIR/bench_ops.txt"
	local ERR="$TMP_DIR/bench_err.txt"
	local CHK="$TMP_DIR/bench_checker_out.txt"
	local CHK_ERR="$TMP_DIR/bench_checker_err.txt"
	local RES

	: > "$OUT"
	: > "$ERR"
	: > "$CHK"
	: > "$CHK_ERR"

	eval "$PS --bench $FLAGS $ARG" > "$OUT" 2> "$ERR"
	eval "$CHECKER $ARG" < "$OUT" > "$CHK" 2> "$CHK_ERR"

	RES=$(cat "$CHK")

	if [ "$RES" != "OK" ]; then
		fail_detail \
			"$NAME" \
			"--bench deve manter stdout apenas com operações válidas para o checker imprimir OK" \
			"checker imprimiu '$RES'" \
			"$PS --bench $FLAGS $ARG | $CHECKER $ARG" \
			"$ARG" \
			"$FLAGS" \
			"$CHK" \
			"$CHK_ERR" \
			"$OUT"
		return
	fi

	if [ ! -s "$ERR" ]; then
		fail_detail \
			"$NAME" \
			"--bench deve escrever métricas no stderr" \
			"stderr veio vazio" \
			"$PS --bench $FLAGS $ARG" \
			"$ARG" \
			"$FLAGS" \
			"$OUT" \
			"$ERR" \
			"$OUT"
		return
	fi

	if grep -Eiq "disorder|strategy|complex|simple|medium|adaptive|operation|ops|sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr" "$ERR"; then
		ok "$NAME | bench ok"
	else
		fail_detail \
			"$NAME" \
			"stderr do --bench deve conter métricas úteis" \
			"stderr existe, mas não parece conter as métricas esperadas" \
			"$PS --bench $FLAGS $ARG" \
			"$ARG" \
			"$FLAGS" \
			"$OUT" \
			"$ERR" \
			"$OUT"
	fi
}

print_title "BINÁRIOS"

if [ ! -x "$PS" ]; then
	echo "ERRO: $PS não existe ou não é executável"
	exit 1
fi

if [ ! -x "$CHECKER" ]; then
	echo "ERRO: checker escolhido não existe ou não é executável: $CHECKER"
	exit 1
fi

echo "push_swap: $PS"
echo "checker usado: $CHECKER"

print_title "SEM ARGUMENTOS"

run_no_arg_test

print_title "TESTES PEQUENOS COM TODAS AS ESTRATÉGIAS"

run_strategy_tests "um número" "1"
run_strategy_tests "dois já ordenados" "1 2"
run_strategy_tests "dois invertidos" "2 1"
run_strategy_tests "três invertidos" "3 2 1"
run_strategy_tests "três caso ra" "3 1 2"
run_strategy_tests "três caso rra" "2 3 1"
run_strategy_tests "cinco invertidos" "5 4 3 2 1"
run_strategy_tests "cinco misturados" "4 67 3 87 23"
run_strategy_tests "negativos e positivos" "-1 -5 3 0 2"
run_strategy_tests "limites de int" "2147483647 -2147483648 0 42 -42"

print_title "TESTES DIRETOS DO CHECKER"

run_checker_test "checker sa OK" "2 1" "sa\n" "OK"
run_checker_test "checker sa KO" "1 2" "sa\n" "KO"
run_checker_test "checker exemplo OK" "3 2 1 0" "rra\npb\nsa\nrra\npa\n" "OK"
run_checker_test "checker exemplo KO" "3 2 1 0" "sa\nrra\npb\n" "KO"

# Corrigidos:
# 3 1 2 + ra  => 1 2 3
# 2 3 1 + rra => 1 2 3
run_checker_test "checker ra OK" "3 1 2" "ra\n" "OK"
run_checker_test "checker rra OK" "2 3 1" "rra\n" "OK"

run_checker_test "checker pa com b vazio" "1 2 3" "pa\n" "OK"
run_checker_test "checker pb pa volta igual" "1 2 3" "pb\npa\n" "OK"
run_checker_test "checker ss com b vazio" "2 1" "ss\n" "OK"

print_title "ERROS DO PUSH_SWAP"

run_push_swap_error_test "duplicado" "1 2 2"
run_push_swap_error_test "letra no argumento" "1 2 abc"
run_push_swap_error_test "maior que int" "2147483648"
run_push_swap_error_test "menor que int" "-2147483649"
run_push_swap_error_test "argumento vazio" '"" 1 2'
run_push_swap_error_test "flag inválida" "--banana 1 2 3"
run_push_swap_error_test "duplicado com flag" "--simple 3 2 3"
run_push_swap_error_test "mais no meio inválido" "1 + 2"
run_push_swap_error_test "sinal sozinho" "1 - 2"
run_push_swap_error_test "número quebrado" "1 2 3.5"
run_push_swap_error_test "número grudado com letra" "1 2a 3"

print_title "ERROS DO CHECKER"

run_checker_error_test "checker argumento duplicado" "1 1" "sa\n"
run_checker_error_test "checker argumento letra" "1 abc 2" "sa\n"
run_checker_error_test "checker maior que int" "2147483648" "sa\n"
run_checker_error_test "checker menor que int" "-2147483649" "sa\n"
run_checker_error_test "checker argumento vazio" '"" 1' "sa\n"
run_checker_error_test "checker instrução inválida" "2 1" "banana\n"
run_checker_error_test "checker instrução maiúscula" "2 1" "SA\n"
run_checker_error_test "checker espaço depois da instrução" "2 1" "sa \n"
run_checker_error_test "checker linha vazia como instrução" "2 1" "sa\n\n"

print_title "TESTES ALEATÓRIOS"

run_random_tests 3 10
run_random_tests 5 10
run_random_tests 10 10
run_random_tests 50 5
run_random_tests 100 5
run_random_tests 500 3

print_title "BENCH"

run_bench_test "bench adaptive" "--adaptive" "4 67 3 87 23"
run_bench_test "bench simple" "--simple" "5 4 3 2 1"
run_bench_test "bench medium" "--medium" "98 12 -4 55 0 31 7 -99 42 16"
run_bench_test "bench complex" "--complex" "98 12 -4 55 0 31 7 -99 42 16"

print_title "RESUMO"

echo -e "${GREEN}PASS:${RESET} $PASS"
echo -e "${RED}FAIL:${RESET} $FAIL"
echo "TOTAL: $TOTAL"

rm -rf "$TMP_DIR"

if [ "$FAIL" -eq 0 ]; then
	echo -e "${GREEN}Tudo passou.${RESET}"
	echo "Próximo passo: roda com valgrind."
	exit 0
else
	echo -e "${RED}Tem coisa quebrada.${RESET}"
	echo "Arquivos úteis do último erro:"
	echo "  $LAST_CMD"
	echo "  $LAST_ARGS"
	echo "  $LAST_OPS"
	exit 1
fi