program primes
implicit none

      integer n
      integer i
      integer, parameter :: i_max = 1000000
      logical :: is_prime(i_max)

      read (*, *) n

      is_prime = .true.
      do i = 2, int (sqrt (real (n)))
        if (is_prime(i)) is_prime(i * i : i_max : i) = .false.
      end do

      do i = 2, n
        if (is_prime(i)) write (*, '(i0, 1x)') i
      end do
end program primes
