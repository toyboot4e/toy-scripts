#!/usr/bin/env bash -euE

# NOTE: `ccurl` (cached curl) must be in your path
# TODO: Just search from local haskell reposiotory :(

word="$1"

url="$(hoogle search --json -n1 "$word" | jq .[].url | sed 's;";;g')"

base_url="$(printf '%s' "$url" | sed -E 's;(.*/).*;\1;g')"
tag="$(printf '%s' "$url" | sed 's;.*#;#;')"

relative_url="$(curl -L -s "$url" | pup ':parent-of(a[href=#v:print])' | pup '.link attr{href}')"
source_url="$(printf '%s/%s' "$base_url" "$relative_url")"

# echo "$url"
# echo "$base_url"
# echo "$relative_url"
# echo "$source_url"

source="$(
    curl "$source_url" -L -s |
        html2text |
        tail -n +2 # remove XML tag
)"

printf '%s' "$source" | bat -l haskell --pager "less -RF --pattern=$word.*::"

