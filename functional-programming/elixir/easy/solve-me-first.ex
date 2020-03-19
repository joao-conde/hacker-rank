defmodule Solution do 
    def solve() do 
        d1 = IO.gets("") |> String.trim_trailing |> String.to_integer
        d2 = IO.gets("") |> String.trim_trailing |> String.to_integer
        IO.puts(d1 + d2)
    end
end

Solution.solve()