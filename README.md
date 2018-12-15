# leetcode-solutions
Solutions to leetcode problems.

>Below is the helper functions/aliases used by me to seamlessly fetch new questions, code it in atom, test and submit solution.


**cat .env.sh**
```
#!/bin/bash
###-begin-leetcode-completions-###
#
# yargs command completion script
#
# Installation: ../.local/bin/leetcode completion >> ~/.bashrc
#    or ../.local/bin/leetcode completion >> ~/.bash_profile on OSX.
#
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

alias lee='leetcode'
alias list='leetcode list'
#alias submit='leetcode submit'
#alias commit='leetcode submit'
#alias show='leetcode show'
alias view='leetcode view'
#alias star='leetcode star'
alias stat='leetcode stat'

function show {
  leetcode show "$@";
  ls -t | head -n1 > .lastAttempt;
}

function run {
	echo "$(cat .lastAttempt)";
	if [ -z "$1" ];then
		leetcode run "$(cat .lastAttempt | tr -d '\n')";
	else
		leetcode run "$(cat .lastAttempt | tr -d '\n')" -t "$1";
	fi
}

function commit {
	echo "$(cat .lastAttempt)";
	leetcode submit "$(cat .lastAttempt | tr -d '\n')";
}

function star {
  Q="$(cat .lastAttempt | tr -d '\n')";
	if [ -z "$1" ]; then
		leetcode star $(echo -n "${Q%%.*}");
	elif [ "$1" = "del" ]; then
		leetcode star $(echo -n "${Q%%.*}") -d;
  else
    leetcode star "$@";
	fi
}
function fetch {
  if [ -z "$1" ]; then
    Q="$(cat .lastAttempt | tr -d '\n')";
		leetcode submission $(echo -n "${Q%%.*}");
	else
    out=$(leetcode submission "$1");
    echo "$out";
    if [ "$(echo -n $out | awk '{ print $NF }')" != "submissions?" ]; then
      atom "$(echo -n $out | awk '{ print $NF }')";
    fi
	fi
}
function solution {
	Q="$(cat .lastAttempt | tr -d '\n')";
  echo "########   Java   ########";
  leetcode show $(echo -n "${Q%%.*}") --solution -l java;
  echo "########   cpp   ########";
  leetcode show $(echo -n "${Q%%.*}") --solution -l cpp;
}
function resume {
  Q="$(cat .lastAttempt | tr -d '\n')";
  leetcode show $(echo -n "${Q%%.*}");
  atom ./"$(cat .lastAttempt | tr -d '\n')";
}
function solve {
  if [ -z "$1" ]; then
    resume;
  else
    show "$1" -gxe -q D;
  fi
}
export -f run
export -f commit
alias submit='commit'
export -f show
export -f star
export -f solution
export -f resume
export -f solve
```
