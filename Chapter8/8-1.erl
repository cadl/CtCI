#!/usr/bin/env escript


main([N]) ->
    I = list_to_integer(N),
    Fib = fib(I),
    io:format("Fib(~w) = ~w~n", [I, Fib]).


fib(1) -> 1;
fib(2) -> 1;
fib(N) ->
    fib(N-1) + fib(N-2).
