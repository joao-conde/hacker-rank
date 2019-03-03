defmodule Solution do
    def solve() do
        [h|t] = IO.read(:stdio, :all) 
        |> String.trim_trailing |> String.split("\n") 
        |> Enum.map(fn x -> String.to_integer(x) end)
        
        Enum.map(t, fn x -> Enum.map(1..h, fn _-> IO.puts(x) end) end)
    end
end

Solution.solve()