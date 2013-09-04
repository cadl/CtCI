#!/usr/bin/env escript


perms([]) ->
    [[]];
perms(L) ->
    [[H|T] || H <- L, T <- perms(L--[H])].


print_list([]) ->
    io:format("~n");
print_list([H|T]) ->
    io:format("~p ", [H]),
    print_list(T).


main([N]) ->
    L = perms(N),
    print_list(L).
