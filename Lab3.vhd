library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity lab3 is
	port (
		clk : in std_logic; -- clk
		leds_7 : out std_logic_vector(47 downto 0); -- export
		reset : in std_logic; -- reset_n
		sda : inout std_logic; -- signal data
		scl : inout std_logic; -- signal I2C's clock
		GSENSOR_CS_n : out std_logic; -- I2C communication "1" enable / "0" disable
		switch : in std_logic_vector(1 downto 0) := (others => 'X') -- export
 
		);
end entity;

architecture rtl of lab3 is

		component lab3_sys is
			port (
				clk_clk : in std_logic := 'X'; -- clk
				leds_external_connection_export : out std_logic_vector(23 downto 0); -- export
				reset_reset_n : in std_logic := 'X'; -- reset_n
				opencores_i2c_0_export_0_scl_pad_io : inout std_logic := 'X'; -- scl_pad_io
				opencores_i2c_0_export_0_sda_pad_io : inout std_logic := 'X';-- sda_pad_io
				pio_0_external_connection_export : in std_logic_vector(1 downto 0) := (others => 'X') -- export
 
 
				);
			end component lab3_sys;

			component bin_to_7seg is
				port (
					B : in STD_LOGIC_VECTOR (3 downto 0);
					S : out STD_LOGIC_VECTOR (7 downto 0)
					--
				);
			end component bin_to_7seg;

			signal leds : std_logic_vector(23 downto 0);

		begin
			GSENSOR_CS_n <= '1';
					
			u0 : component lab3_sys
			port map(
				clk_clk => clk, --clk
				leds_external_connection_export => leds, -- leds_external_connection.export
				reset_reset_n => reset, --reset
				opencores_i2c_0_export_0_scl_pad_io => scl, --i2c
				opencores_i2c_0_export_0_sda_pad_io => sda, --sda
				pio_0_external_connection_export => switch -- pio_0_external_connection.export
			);



			u1 : component bin_to_7seg
			port map(
				B => leds(3 downto 0), -- clk.clk
				S => leds_7(7 downto 0) -- leds_external_connection.export
			);

			u2 : component bin_to_7seg
			port map(
				B => leds(7 downto 4), -- clk.clk
				S => leds_7(15 downto 8) -- leds_external_connection.export
			);

			u3 : component bin_to_7seg
			port map(
				B => leds(11 downto 8), -- clk.clk
				S => leds_7(23 downto 16) -- leds_external_connection.export
			);
 
			u4 : component bin_to_7seg
			port map(
				B => leds(15 downto 12), -- clk.clk
				S => leds_7(31 downto 24) -- leds_external_connection.export
			);
 
 
			u5 : component bin_to_7seg
			port map(
				B => leds(19 downto 16), -- clk.clk
				S => leds_7(39 downto 32) -- leds_external_connection.export
			);
 
			u6 : component bin_to_7seg
			port map(
				B => leds(23 downto 20), -- clk.clk
				S => leds_7(47 downto 40) -- leds_external_connection.export
			);
end architecture;