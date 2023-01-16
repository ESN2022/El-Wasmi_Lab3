library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity lab3 is
	port(
		clk                              : in  std_logic                    ; -- clk
		reset                            : in  std_logic                    ; -- reset_n
		sda										: inout std_logic						  ; -- signal data
		scl										: inout std_logic						  ; -- signal I2C's clock
	   GSENSOR_CS_n 							: out std_logic  								 -- I2C communication "1" enable / "0" disable
 	);
end entity;

architecture rtl of lab3 is
	
	component lab3_sys is
		port (
			clk_clk                             : in    std_logic := 'X'; -- clk
			reset_reset_n                       : in    std_logic := 'X'; -- reset_n
			opencores_i2c_0_export_0_scl_pad_io : inout std_logic := 'X'; -- scl_pad_io
			opencores_i2c_0_export_0_sda_pad_io : inout std_logic := 'X'  -- sda_pad_io
		);
	end component lab3_sys;

begin
	u0 : component lab3_sys
		port map (
			clk_clk                             => clk,                         --clk
			reset_reset_n                       => reset,                       --reset
			opencores_i2c_0_export_0_scl_pad_io => scl, 								  --i2c
			opencores_i2c_0_export_0_sda_pad_io => sda                          --sda
	);
	GSENSOR_CS_n <= '1';
end architecture;