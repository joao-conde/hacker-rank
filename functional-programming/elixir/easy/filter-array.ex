defmodule Solution do
    def solve() do
        [h|t] = IO.read(:stdio, :all) 
        |> String.trim_trailing |> String.split("\n") |> Enum.map(fn x -> String.to_integer(x) end)

        Enum.filter(t, fn x -> x < h end) |> Enum.map(fn x -> IO.puts(x) end)
    end
end

Solution.solve()