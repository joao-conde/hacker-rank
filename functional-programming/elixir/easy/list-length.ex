defmodule Solution do
    def solve() do
        IO.read(:stdio, :all) 
        |> String.trim_trailing |> String.split("\n")
        |> length |> IO.puts()
    end
end 

Solution.solve()