library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.float_pkg.all;
use ieee.fixed_pkg.all;

entity tb_math_op_unsign is
end entity tb_math_op_unsign;


architecture verify of tb_math_op_unsign is
  signal X, Y : ufixed(4 downto -2);
  signal Z    : sfixed(8 downto -2);

  begin
    duv : entity work.math_op_unsign(behave)
      port map (X => X, Y => Y, Z => Z);

    apply_test_cases : process is
      procedure apply_test
        ( X_test, Y_test : ufixed(4 downto -2) ) is
      begin
        X <= X_test;
        Y <= Y_test;
        wait for 1 ms;
      end procedure apply_test;

  begin
    apply_test(to_ufixed(1.5, 4, -2), to_ufixed(5.5, 4, -2));
    apply_test(to_ufixed(-2.5, 4, -2), to_ufixed(3.5, 4, -2));
    apply_test(to_ufixed(7.5, 4, -2), to_ufixed(0.0, 4, -2));
    apply_test(to_ufixed(0.0, 4, -2), to_ufixed(7.5, 4, -2));
    apply_test(to_ufixed(1.5, 4, -2), to_ufixed(-5.5, 4, -2));
    wait;
  end process apply_test_cases;
end architecture verify;