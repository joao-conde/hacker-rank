defmodule Solution do
    def solve() do
        IO.read(:stdio, :all) |> String.trim_trailing |> String.split("\n") 
        |> Enum.with_index(1) |> Enum.filter(fn {_, i} -> rem(i, 2) == 0 end) 
        |> Enum.map(fn {x, _} -> IO.puts(x) end)
    end
end

Solution.solve()