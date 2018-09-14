library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

entity BitCounter is
	port (
		ADC_CLK_10    : in  std_logic;
		MAX10_CLK1_50 : in  std_logic;
		MAX10_CLK2_50 : in  std_logic;
		KEY           : in  std_logic_vector(1 downto 0);
		LEDR          : out std_logic_vector(9 downto 0) := "0000000000"
	);
end BitCounter;


architecture Behavior of BitCounter is
	signal clk_ctr : integer   := 1;
	signal clk_1hz : std_logic := '0';
	signal Q       : std_logic_vector(9 downto 0);
begin
	process (ADC_CLK_10, KEY(0)) is
	begin
		-- reset button
		if (KEY(0) = '0') then
			Q       <= Q and not Q;
			clk_ctr <= 1;
			clk_1hz <= '0';
		
		-- devides the clock by 10E6 (1 Hz)
		elsif (ADC_CLK_10'event and ADC_CLK_10='1') then
			clk_ctr <= clk_ctr + 1;
			if (clk_ctr = 10000000) then
				clk_ctr <= 1;
				clk_1hz <= not clk_1hz;
				-- update LED counter
				Q <= Q + 1;
			end if;
		end if;
	end process;
	
	LEDR <= Q;

end Behavior;
