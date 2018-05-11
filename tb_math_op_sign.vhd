library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.float_pkg.all;
use ieee.fixed_pkg.all;

entity tb_math_op_sign is
end entity tb_math_op_sign;

architecture verify of tb_math_op_sign is
  signal X, Y : sfixed(4 downto -2);
  signal Z    : sfixed(9 downto -2);
  
  begin
    duv : entity work.math_op_sign(behave)
      port map ( X => X, Y => Y, Z => Z);

    apply_test_cases : process is
      procedure apply_test
        ( X_test, Y_test : in sfixed(4 downto -2) ) is
      begin
        X <= X_test;
        Y <= Y_test;
        wait for 1 ms;
      end procedure apply_test;

  begin
    apply_test(to_sfixed(1.5, 4, -2), to_sfixed(5.5, 4, -2));
    apply_test(to_sfixed(-2.5, 4, -2), to_sfixed(3.5, 4, -2));
    apply_test(to_sfixed(7.5, 4, -2), to_sfixed(0.0, 4, -2));
    apply_test(to_sfixed(0.0, 4, -2), to_sfixed(7.5, 4, -2));
    wait;
  end process apply_test_cases;
end architecture verify;
      
