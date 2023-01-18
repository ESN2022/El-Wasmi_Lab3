LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY lab3 IS
	PORT (
		clk : IN std_logic; -- clk
		leds_7 : OUT std_logic_vector(47 DOWNTO 0); -- export
		reset : IN std_logic; -- reset_n
		sda : INOUT std_logic; -- signal data
		scl : INOUT std_logic; -- signal I2C's clock
		GSENSOR_CS_n : OUT std_logic; -- I2C communication "1" enable / "0" disable
		switch    : in    std_logic_vector(1 downto 0)  := (others => 'X')  -- export
     
	);
END ENTITY;

ARCHITECTURE rtl OF lab3 IS
 
	COMPONENT lab3_sys IS
		PORT (
			clk_clk : IN std_logic := 'X'; -- clk
			leds_external_connection_export : OUT std_logic_vector(23 DOWNTO 0); -- export
			reset_reset_n : IN std_logic := 'X'; -- reset_n
			opencores_i2c_0_export_0_scl_pad_io : INOUT std_logic := 'X'; -- scl_pad_io
			opencores_i2c_0_export_0_sda_pad_io : INOUT std_logic := 'X'  ;-- sda_pad_io
		   pio_0_external_connection_export    : in    std_logic_vector(1 downto 0)  := (others => 'X')  -- export
   
   
		);
	END COMPONENT lab3_sys;
 
	COMPONENT bin_to_7seg IS
		PORT (
			B : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
			S : OUT STD_LOGIC_VECTOR (7 DOWNTO 0)
			-- 
		);
	END COMPONENT bin_to_7seg;

	SIGNAL leds : std_logic_vector(23 DOWNTO 0);

BEGIN
	u0 : COMPONENT lab3_sys
	PORT MAP(
		clk_clk => clk, --clk
		leds_external_connection_export => leds, -- leds_external_connection.export
		reset_reset_n => reset, --reset
		opencores_i2c_0_export_0_scl_pad_io => scl, --i2c
		opencores_i2c_0_export_0_sda_pad_io => sda, --sda
		   pio_0_external_connection_export    => switch     -- pio_0_external_connection.export
	);
 
	GSENSOR_CS_n <= '1';
 
	u1 : COMPONENT bin_to_7seg
	PORT MAP(
		B => leds(3 DOWNTO 0), -- clk.clk
		S => leds_7(7 DOWNTO 0) -- leds_external_connection.export
	);
 
	u2 : COMPONENT bin_to_7seg
	PORT MAP(
		B => leds(7 DOWNTO 4), -- clk.clk
		S => leds_7(15 DOWNTO 8) -- leds_external_connection.export
	);

	u3 : COMPONENT bin_to_7seg
	PORT MAP(
		B => leds(11 DOWNTO 8), -- clk.clk
		S => leds_7(23 DOWNTO 16) -- leds_external_connection.export
	);
	
	u4 : COMPONENT bin_to_7seg
	PORT MAP(
		B => leds(15 DOWNTO 12), -- clk.clk
		S => leds_7(31 DOWNTO 24) -- leds_external_connection.export
	);
	
	
	u5 : COMPONENT bin_to_7seg
	PORT MAP(
		B => leds(19 DOWNTO 16), -- clk.clk
		S => leds_7(39 DOWNTO 32) -- leds_external_connection.export
	);
	
	u6 : COMPONENT bin_to_7seg
	PORT MAP(
		B => leds(23 DOWNTO 20), -- clk.clk
		S => leds_7(47 DOWNTO 40) -- leds_external_connection.export
	);
END ARCHITECTURE;