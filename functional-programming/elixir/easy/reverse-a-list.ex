defmodule Solution do
    def solve() do
        IO.read(:stdio, :all) |> String.split("\n") |> Enum.reverse |> Enum.map(fn x -> IO.puts(x) end)
    end
end

Solution.solve()