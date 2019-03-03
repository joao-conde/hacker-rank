defmodule Solution do
    def solve() do
        range = 1..(IO.gets("") |> String.trim_trailing |> String.to_integer)
        Enum.map(range, fn _ -> IO.puts("Hello World") end)
    end
end

Solution.solve()