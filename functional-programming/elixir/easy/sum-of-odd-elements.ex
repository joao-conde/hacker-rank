defmodule Solution do
    def solve() do
        IO.read(:stdio, :all) 
        |> String.trim_trailing |> String.split("\n")
        |> Enum.map(fn x -> String.to_integer(x) end)
        |> Enum.filter(fn x -> rem(x, 2) != 0 end) 
        |> Enum.reduce(fn x, acc -> acc + x end) |> IO.puts()
    end
end

Solution.solve()