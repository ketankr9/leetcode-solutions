# leetcode-solutions
Solutions to leetcode problems.

>Below is the helper functions/aliases used by me to seamlessly fetch new questions, code it in atom, test and submit solution.


**cat .env.sh**
```
#!/bin/bash

LLANG="java"
EDITOR="sublime-text.subl"
LEETCODE='/home/user/.local/bin/leetcode'

_yargs_completions()
{
    local cur_word args type_list

    cur_word="${COMP_WORDS[COMP_CWORD]}"
    args=("${COMP_WORDS[@]}")

    # ask yargs to generate completions.
    type_list=$(../.local/bin/leetcode --get-yargs-completions "${args[@]}")

    COMPREPLY=( $(compgen -W "${type_list}" -- ${cur_word}) )

    # if no match was found, fall back to filename completion
    if [ ${#COMPREPLY[@]} -eq 0 ]; then
      COMPREPLY=( $(compgen -f -- "${cur_word}" ) )
    fi

    return 0
}
complete -F _yargs_completions leetcode
###-end-leetcode-completions-###


alias lee="$LEETCODE"
alias leetcode="$LEETCODE"
alias list='$LEETCODE list'
#alias submit='leetcode submit'
#alias commit='leetcode submit'
#alias show='leetcode show'
alias view='$LEETCODE view'
#alias star='leetcode star'
alias stat='$LEETCODE stat'

function show {
  "$LEETCODE" show "$@";
  ls -t | head -n1 > .lastAttempt;
}

function run {
	ls -t | head -n1 > .lastAttempt;
	echo "$(cat .lastAttempt)";
	if [ -z "$1" ];then
		"$LEETCODE" run "$(cat .lastAttempt | tr -d '\n')";
	else
		"$LEETCODE" run "$(cat .lastAttempt | tr -d '\n')" -t "$@";
	fi
}

function commit {
	ls -t | head -n1 > .lastAttempt;
	echo "$(cat .lastAttempt)";
	"$LEETCODE" submit "$(cat .lastAttempt | tr -d '\n')";
}

function star {
  Q="$(cat .lastAttempt | tr -d '\n')";
	if [ -z "$1" ]; then
		"$LEETCODE" star $(echo -n "${Q%%.*}");
	elif [ "$1" = "del" ]; then
		"$LEETCODE" star $(echo -n "${Q%%.*}") -d;
  else
    "$LEETCODE" star "$@";
	fi
}
function fetch {
  if [ -z "$1" ]; then
    Q="$(cat .lastAttempt | tr -d '\n')";
		"$LEETCODE" submission $(echo -n "${Q%%.*}");
	else
    out=$("$LEETCODE" submission "$1");
    echo "$out";
    if [ "$(echo -n $out | awk '{ print $NF }')" != "submissions?" ]; then
      $($EDITOR "$(echo -n $out | awk '{ print $NF }')");
    fi
	fi
}
function solution {
	Q="$(cat .lastAttempt | tr -d '\n')";
  echo "########   Java   ########";
  "$LEETCODE" show $(echo -n "${Q%%.*}") --solution -l java;
  echo "########   cpp   ########";
  "$LEETCODE" show $(echo -n "${Q%%.*}") --solution -l cpp;
}
function resume {
  Q="$(cat .lastAttempt | tr -d '\n')";
  "$LEETCODE" show $(echo -n "${Q%%.*}");
  $($EDITOR "$(cat .lastAttempt | tr -d '\n')");
}
alias startt="xterm -geometry 45x21-0+0 termdown &";

function restartTimer {
  pkill -f termdown
  xterm -geometry 48x27-0+0 termdown &
  # pkill -f leetimer
  # ./.leetimer.sh &
}

function solve {
  if [ -z "$1" ]; then
    resume;
  elif [ -z "$2" ] && [ ! -z "$(ls | grep -i "^$1\.")" ]; then
    "$EDITOR" "$(ls | grep -i "^$1\." | head -n1)";
  else
    "$LEETCODE" show "$1" -gx -e "${EDITOR}" -q D -l ${LLANG};
  fi
  restartTimer;
}

export -f run
export -f commit
alias submit='commit'
export -f show
export -f star
export -f solution
export -f resume
export -f solve
alias up='ls -t | head -n1 > .lastAttempt'
```
