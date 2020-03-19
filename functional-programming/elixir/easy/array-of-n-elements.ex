defmodule Solution do
    def solve() do
        Enum.to_list(1..(IO.gets("") |> String.trim_trailing |> String.to_integer)) 
        |> IO.inspect(limit: :infinity)
    end
end

Solution.solve()