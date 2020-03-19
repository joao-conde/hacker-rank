defmodule Solution do
    def solve() do
        IO.read(:stdio, :all)
        |> String.trim_trailing |> String.split("\n")
        |> Enum.map(fn x -> IO.puts(abs(String.to_integer(x))) end)
    end
end

Solution.solve()