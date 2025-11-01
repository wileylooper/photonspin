#### PhotonSpin64

PhotonSpin64 provides enhanced period, speed and statistical test results as an ideal alternative to SHISHUA.

It has a period of at least 2¹⁰²⁴.

Each state integer must be assigned a seed. The first 20 integers from each instance should be skipped.

`photonSpin64` generates and assigns 20 pseudorandom `uint64_t` integers to `elements`, provided the implementation supports a 64-bit, unsigned integral type for `uint64_t`.

---

#### PhotonSpin32

PhotonSpin32 is a scaled-down variant of PhotonSpin64 that uses 32-bit integers instead of 64-bit integers.

It has a period of at least 2⁵¹².

Each state integer must be assigned a seed. The first 20 integers from each instance should be skipped.

`photonSpin32` generates and assigns 20 pseudorandom `uint32_t` integers to `elements`, provided the implementation supports a 32-bit, unsigned integral type for `uint32_t`.
