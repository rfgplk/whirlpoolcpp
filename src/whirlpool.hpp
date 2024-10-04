#pragma once

#include <array>
#include <concepts>
#include <cstdint>
#include <cstring>
#include <type_traits>
namespace whrlpl
{

template <typename T>
concept stl_container = requires(T t) {
  { t.begin() } -> std::same_as<typename T::iterator>;
  { t.end() } -> std::same_as<typename T::iterator>;
  { t.cbegin() } -> std::same_as<typename T::const_iterator>;
  { t.cend() } -> std::same_as<typename T::const_iterator>;
  { t.size() } -> std::same_as<typename T::size_type>;
  { t.data() } -> std::same_as<typename T::pointer>;
};

template <typename T>
inline bool
aligned(T ptr)
{
  return (0 == (7 & (__UINTPTR_TYPE__)(ptr)));
}
typedef __INT8_TYPE__ i8;
typedef __INT16_TYPE__ i16;
typedef __INT32_TYPE__ i32;
typedef __INT64_TYPE__ i64;

typedef __INTPTR_TYPE__ intptr_t;
typedef __UINT8_TYPE__ u8;
typedef __UINT16_TYPE__ u16;
typedef __UINT32_TYPE__ u32;
typedef __UINT64_TYPE__ u64;

typedef __INTMAX_TYPE__ ssize_t;
typedef __UINTMAX_TYPE__ size_t;

constexpr static const __UINT8_TYPE__ padding[64] = { 0x00 };
constexpr u64 blck_sz = 64;      // 64 * 8 = 512
constexpr u64 digest_sz = 8;     // 8 * 64 = 256

constexpr static const __UINT64_TYPE__ whirl_rc[10]
    = { (0x1823c6e887b8014fULL), (0x36a6d2f5796f9152ULL), (0x60bc9b8ea30c7b35ULL), (0x1de0d7c22e4bfe57ULL),
        (0x157737e59ff04adaULL), (0x58c9290ab1a06b85ULL), (0xbd5d10f4cb3e0567ULL), (0xe427418ba77d95d8ULL),
        (0xfbee7c66dd17479eULL), (0xca2dbf07ad5a8333ULL) };

constexpr static const __UINT64_TYPE__ whirlpool_sbox[8][256]
    = { {
            /* C0 vectors */
            (0x18186018c07830d8ULL), (0x23238c2305af4626ULL), (0xc6c63fc67ef991b8ULL), (0xe8e887e8136fcdfbULL),
            (0x878726874ca113cbULL), (0xb8b8dab8a9626d11ULL), (0x0101040108050209ULL), (0x4f4f214f426e9e0dULL),
            (0x3636d836adee6c9bULL), (0xa6a6a2a6590451ffULL), (0xd2d26fd2debdb90cULL), (0xf5f5f3f5fb06f70eULL),
            (0x7979f979ef80f296ULL), (0x6f6fa16f5fcede30ULL), (0x91917e91fcef3f6dULL), (0x52525552aa07a4f8ULL),
            (0x60609d6027fdc047ULL), (0xbcbccabc89766535ULL), (0x9b9b569baccd2b37ULL), (0x8e8e028e048c018aULL),
            (0xa3a3b6a371155bd2ULL), (0x0c0c300c603c186cULL), (0x7b7bf17bff8af684ULL), (0x3535d435b5e16a80ULL),
            (0x1d1d741de8693af5ULL), (0xe0e0a7e05347ddb3ULL), (0xd7d77bd7f6acb321ULL), (0xc2c22fc25eed999cULL),
            (0x2e2eb82e6d965c43ULL), (0x4b4b314b627a9629ULL), (0xfefedffea321e15dULL), (0x575741578216aed5ULL),
            (0x15155415a8412abdULL), (0x7777c1779fb6eee8ULL), (0x3737dc37a5eb6e92ULL), (0xe5e5b3e57b56d79eULL),
            (0x9f9f469f8cd92313ULL), (0xf0f0e7f0d317fd23ULL), (0x4a4a354a6a7f9420ULL), (0xdada4fda9e95a944ULL),
            (0x58587d58fa25b0a2ULL), (0xc9c903c906ca8fcfULL), (0x2929a429558d527cULL), (0x0a0a280a5022145aULL),
            (0xb1b1feb1e14f7f50ULL), (0xa0a0baa0691a5dc9ULL), (0x6b6bb16b7fdad614ULL), (0x85852e855cab17d9ULL),
            (0xbdbdcebd8173673cULL), (0x5d5d695dd234ba8fULL), (0x1010401080502090ULL), (0xf4f4f7f4f303f507ULL),
            (0xcbcb0bcb16c08bddULL), (0x3e3ef83eedc67cd3ULL), (0x0505140528110a2dULL), (0x676781671fe6ce78ULL),
            (0xe4e4b7e47353d597ULL), (0x27279c2725bb4e02ULL), (0x4141194132588273ULL), (0x8b8b168b2c9d0ba7ULL),
            (0xa7a7a6a7510153f6ULL), (0x7d7de97dcf94fab2ULL), (0x95956e95dcfb3749ULL), (0xd8d847d88e9fad56ULL),
            (0xfbfbcbfb8b30eb70ULL), (0xeeee9fee2371c1cdULL), (0x7c7ced7cc791f8bbULL), (0x6666856617e3cc71ULL),
            (0xdddd53dda68ea77bULL), (0x17175c17b84b2eafULL), (0x4747014702468e45ULL), (0x9e9e429e84dc211aULL),
            (0xcaca0fca1ec589d4ULL), (0x2d2db42d75995a58ULL), (0xbfbfc6bf9179632eULL), (0x07071c07381b0e3fULL),
            (0xadad8ead012347acULL), (0x5a5a755aea2fb4b0ULL), (0x838336836cb51befULL), (0x3333cc3385ff66b6ULL),
            (0x636391633ff2c65cULL), (0x02020802100a0412ULL), (0xaaaa92aa39384993ULL), (0x7171d971afa8e2deULL),
            (0xc8c807c80ecf8dc6ULL), (0x19196419c87d32d1ULL), (0x494939497270923bULL), (0xd9d943d9869aaf5fULL),
            (0xf2f2eff2c31df931ULL), (0xe3e3abe34b48dba8ULL), (0x5b5b715be22ab6b9ULL), (0x88881a8834920dbcULL),
            (0x9a9a529aa4c8293eULL), (0x262698262dbe4c0bULL), (0x3232c8328dfa64bfULL), (0xb0b0fab0e94a7d59ULL),
            (0xe9e983e91b6acff2ULL), (0x0f0f3c0f78331e77ULL), (0xd5d573d5e6a6b733ULL), (0x80803a8074ba1df4ULL),
            (0xbebec2be997c6127ULL), (0xcdcd13cd26de87ebULL), (0x3434d034bde46889ULL), (0x48483d487a759032ULL),
            (0xffffdbffab24e354ULL), (0x7a7af57af78ff48dULL), (0x90907a90f4ea3d64ULL), (0x5f5f615fc23ebe9dULL),
            (0x202080201da0403dULL), (0x6868bd6867d5d00fULL), (0x1a1a681ad07234caULL), (0xaeae82ae192c41b7ULL),
            (0xb4b4eab4c95e757dULL), (0x54544d549a19a8ceULL), (0x93937693ece53b7fULL), (0x222288220daa442fULL),
            (0x64648d6407e9c863ULL), (0xf1f1e3f1db12ff2aULL), (0x7373d173bfa2e6ccULL), (0x12124812905a2482ULL),
            (0x40401d403a5d807aULL), (0x0808200840281048ULL), (0xc3c32bc356e89b95ULL), (0xecec97ec337bc5dfULL),
            (0xdbdb4bdb9690ab4dULL), (0xa1a1bea1611f5fc0ULL), (0x8d8d0e8d1c830791ULL), (0x3d3df43df5c97ac8ULL),
            (0x97976697ccf1335bULL), (0x0000000000000000ULL), (0xcfcf1bcf36d483f9ULL), (0x2b2bac2b4587566eULL),
            (0x7676c57697b3ece1ULL), (0x8282328264b019e6ULL), (0xd6d67fd6fea9b128ULL), (0x1b1b6c1bd87736c3ULL),
            (0xb5b5eeb5c15b7774ULL), (0xafaf86af112943beULL), (0x6a6ab56a77dfd41dULL), (0x50505d50ba0da0eaULL),
            (0x45450945124c8a57ULL), (0xf3f3ebf3cb18fb38ULL), (0x3030c0309df060adULL), (0xefef9bef2b74c3c4ULL),
            (0x3f3ffc3fe5c37edaULL), (0x55554955921caac7ULL), (0xa2a2b2a2791059dbULL), (0xeaea8fea0365c9e9ULL),
            (0x656589650fecca6aULL), (0xbabad2bab9686903ULL), (0x2f2fbc2f65935e4aULL), (0xc0c027c04ee79d8eULL),
            (0xdede5fdebe81a160ULL), (0x1c1c701ce06c38fcULL), (0xfdfdd3fdbb2ee746ULL), (0x4d4d294d52649a1fULL),
            (0x92927292e4e03976ULL), (0x7575c9758fbceafaULL), (0x06061806301e0c36ULL), (0x8a8a128a249809aeULL),
            (0xb2b2f2b2f940794bULL), (0xe6e6bfe66359d185ULL), (0x0e0e380e70361c7eULL), (0x1f1f7c1ff8633ee7ULL),
            (0x6262956237f7c455ULL), (0xd4d477d4eea3b53aULL), (0xa8a89aa829324d81ULL), (0x96966296c4f43152ULL),
            (0xf9f9c3f99b3aef62ULL), (0xc5c533c566f697a3ULL), (0x2525942535b14a10ULL), (0x59597959f220b2abULL),
            (0x84842a8454ae15d0ULL), (0x7272d572b7a7e4c5ULL), (0x3939e439d5dd72ecULL), (0x4c4c2d4c5a619816ULL),
            (0x5e5e655eca3bbc94ULL), (0x7878fd78e785f09fULL), (0x3838e038ddd870e5ULL), (0x8c8c0a8c14860598ULL),
            (0xd1d163d1c6b2bf17ULL), (0xa5a5aea5410b57e4ULL), (0xe2e2afe2434dd9a1ULL), (0x616199612ff8c24eULL),
            (0xb3b3f6b3f1457b42ULL), (0x2121842115a54234ULL), (0x9c9c4a9c94d62508ULL), (0x1e1e781ef0663ceeULL),
            (0x4343114322528661ULL), (0xc7c73bc776fc93b1ULL), (0xfcfcd7fcb32be54fULL), (0x0404100420140824ULL),
            (0x51515951b208a2e3ULL), (0x99995e99bcc72f25ULL), (0x6d6da96d4fc4da22ULL), (0x0d0d340d68391a65ULL),
            (0xfafacffa8335e979ULL), (0xdfdf5bdfb684a369ULL), (0x7e7ee57ed79bfca9ULL), (0x242490243db44819ULL),
            (0x3b3bec3bc5d776feULL), (0xabab96ab313d4b9aULL), (0xcece1fce3ed181f0ULL), (0x1111441188552299ULL),
            (0x8f8f068f0c890383ULL), (0x4e4e254e4a6b9c04ULL), (0xb7b7e6b7d1517366ULL), (0xebeb8beb0b60cbe0ULL),
            (0x3c3cf03cfdcc78c1ULL), (0x81813e817cbf1ffdULL), (0x94946a94d4fe3540ULL), (0xf7f7fbf7eb0cf31cULL),
            (0xb9b9deb9a1676f18ULL), (0x13134c13985f268bULL), (0x2c2cb02c7d9c5851ULL), (0xd3d36bd3d6b8bb05ULL),
            (0xe7e7bbe76b5cd38cULL), (0x6e6ea56e57cbdc39ULL), (0xc4c437c46ef395aaULL), (0x03030c03180f061bULL),
            (0x565645568a13acdcULL), (0x44440d441a49885eULL), (0x7f7fe17fdf9efea0ULL), (0xa9a99ea921374f88ULL),
            (0x2a2aa82a4d825467ULL), (0xbbbbd6bbb16d6b0aULL), (0xc1c123c146e29f87ULL), (0x53535153a202a6f1ULL),
            (0xdcdc57dcae8ba572ULL), (0x0b0b2c0b58271653ULL), (0x9d9d4e9d9cd32701ULL), (0x6c6cad6c47c1d82bULL),
            (0x3131c43195f562a4ULL), (0x7474cd7487b9e8f3ULL), (0xf6f6fff6e309f115ULL), (0x464605460a438c4cULL),
            (0xacac8aac092645a5ULL), (0x89891e893c970fb5ULL), (0x14145014a04428b4ULL), (0xe1e1a3e15b42dfbaULL),
            (0x16165816b04e2ca6ULL), (0x3a3ae83acdd274f7ULL), (0x6969b9696fd0d206ULL), (0x09092409482d1241ULL),
            (0x7070dd70a7ade0d7ULL), (0xb6b6e2b6d954716fULL), (0xd0d067d0ceb7bd1eULL), (0xeded93ed3b7ec7d6ULL),
            (0xcccc17cc2edb85e2ULL), (0x424215422a578468ULL), (0x98985a98b4c22d2cULL), (0xa4a4aaa4490e55edULL),
            (0x2828a0285d885075ULL), (0x5c5c6d5cda31b886ULL), (0xf8f8c7f8933fed6bULL), (0x8686228644a411c2ULL),
        },
        {
            /* C1 vectors */
            (0xd818186018c07830ULL), (0x2623238c2305af46ULL), (0xb8c6c63fc67ef991ULL), (0xfbe8e887e8136fcdULL),
            (0xcb878726874ca113ULL), (0x11b8b8dab8a9626dULL), (0x0901010401080502ULL), (0x0d4f4f214f426e9eULL),
            (0x9b3636d836adee6cULL), (0xffa6a6a2a6590451ULL), (0x0cd2d26fd2debdb9ULL), (0x0ef5f5f3f5fb06f7ULL),
            (0x967979f979ef80f2ULL), (0x306f6fa16f5fcedeULL), (0x6d91917e91fcef3fULL), (0xf852525552aa07a4ULL),
            (0x4760609d6027fdc0ULL), (0x35bcbccabc897665ULL), (0x379b9b569baccd2bULL), (0x8a8e8e028e048c01ULL),
            (0xd2a3a3b6a371155bULL), (0x6c0c0c300c603c18ULL), (0x847b7bf17bff8af6ULL), (0x803535d435b5e16aULL),
            (0xf51d1d741de8693aULL), (0xb3e0e0a7e05347ddULL), (0x21d7d77bd7f6acb3ULL), (0x9cc2c22fc25eed99ULL),
            (0x432e2eb82e6d965cULL), (0x294b4b314b627a96ULL), (0x5dfefedffea321e1ULL), (0xd5575741578216aeULL),
            (0xbd15155415a8412aULL), (0xe87777c1779fb6eeULL), (0x923737dc37a5eb6eULL), (0x9ee5e5b3e57b56d7ULL),
            (0x139f9f469f8cd923ULL), (0x23f0f0e7f0d317fdULL), (0x204a4a354a6a7f94ULL), (0x44dada4fda9e95a9ULL),
            (0xa258587d58fa25b0ULL), (0xcfc9c903c906ca8fULL), (0x7c2929a429558d52ULL), (0x5a0a0a280a502214ULL),
            (0x50b1b1feb1e14f7fULL), (0xc9a0a0baa0691a5dULL), (0x146b6bb16b7fdad6ULL), (0xd985852e855cab17ULL),
            (0x3cbdbdcebd817367ULL), (0x8f5d5d695dd234baULL), (0x9010104010805020ULL), (0x07f4f4f7f4f303f5ULL),
            (0xddcbcb0bcb16c08bULL), (0xd33e3ef83eedc67cULL), (0x2d0505140528110aULL), (0x78676781671fe6ceULL),
            (0x97e4e4b7e47353d5ULL), (0x0227279c2725bb4eULL), (0x7341411941325882ULL), (0xa78b8b168b2c9d0bULL),
            (0xf6a7a7a6a7510153ULL), (0xb27d7de97dcf94faULL), (0x4995956e95dcfb37ULL), (0x56d8d847d88e9fadULL),
            (0x70fbfbcbfb8b30ebULL), (0xcdeeee9fee2371c1ULL), (0xbb7c7ced7cc791f8ULL), (0x716666856617e3ccULL),
            (0x7bdddd53dda68ea7ULL), (0xaf17175c17b84b2eULL), (0x454747014702468eULL), (0x1a9e9e429e84dc21ULL),
            (0xd4caca0fca1ec589ULL), (0x582d2db42d75995aULL), (0x2ebfbfc6bf917963ULL), (0x3f07071c07381b0eULL),
            (0xacadad8ead012347ULL), (0xb05a5a755aea2fb4ULL), (0xef838336836cb51bULL), (0xb63333cc3385ff66ULL),
            (0x5c636391633ff2c6ULL), (0x1202020802100a04ULL), (0x93aaaa92aa393849ULL), (0xde7171d971afa8e2ULL),
            (0xc6c8c807c80ecf8dULL), (0xd119196419c87d32ULL), (0x3b49493949727092ULL), (0x5fd9d943d9869aafULL),
            (0x31f2f2eff2c31df9ULL), (0xa8e3e3abe34b48dbULL), (0xb95b5b715be22ab6ULL), (0xbc88881a8834920dULL),
            (0x3e9a9a529aa4c829ULL), (0x0b262698262dbe4cULL), (0xbf3232c8328dfa64ULL), (0x59b0b0fab0e94a7dULL),
            (0xf2e9e983e91b6acfULL), (0x770f0f3c0f78331eULL), (0x33d5d573d5e6a6b7ULL), (0xf480803a8074ba1dULL),
            (0x27bebec2be997c61ULL), (0xebcdcd13cd26de87ULL), (0x893434d034bde468ULL), (0x3248483d487a7590ULL),
            (0x54ffffdbffab24e3ULL), (0x8d7a7af57af78ff4ULL), (0x6490907a90f4ea3dULL), (0x9d5f5f615fc23ebeULL),
            (0x3d202080201da040ULL), (0x0f6868bd6867d5d0ULL), (0xca1a1a681ad07234ULL), (0xb7aeae82ae192c41ULL),
            (0x7db4b4eab4c95e75ULL), (0xce54544d549a19a8ULL), (0x7f93937693ece53bULL), (0x2f222288220daa44ULL),
            (0x6364648d6407e9c8ULL), (0x2af1f1e3f1db12ffULL), (0xcc7373d173bfa2e6ULL), (0x8212124812905a24ULL),
            (0x7a40401d403a5d80ULL), (0x4808082008402810ULL), (0x95c3c32bc356e89bULL), (0xdfecec97ec337bc5ULL),
            (0x4ddbdb4bdb9690abULL), (0xc0a1a1bea1611f5fULL), (0x918d8d0e8d1c8307ULL), (0xc83d3df43df5c97aULL),
            (0x5b97976697ccf133ULL), (0x0000000000000000ULL), (0xf9cfcf1bcf36d483ULL), (0x6e2b2bac2b458756ULL),
            (0xe17676c57697b3ecULL), (0xe68282328264b019ULL), (0x28d6d67fd6fea9b1ULL), (0xc31b1b6c1bd87736ULL),
            (0x74b5b5eeb5c15b77ULL), (0xbeafaf86af112943ULL), (0x1d6a6ab56a77dfd4ULL), (0xea50505d50ba0da0ULL),
            (0x5745450945124c8aULL), (0x38f3f3ebf3cb18fbULL), (0xad3030c0309df060ULL), (0xc4efef9bef2b74c3ULL),
            (0xda3f3ffc3fe5c37eULL), (0xc755554955921caaULL), (0xdba2a2b2a2791059ULL), (0xe9eaea8fea0365c9ULL),
            (0x6a656589650feccaULL), (0x03babad2bab96869ULL), (0x4a2f2fbc2f65935eULL), (0x8ec0c027c04ee79dULL),
            (0x60dede5fdebe81a1ULL), (0xfc1c1c701ce06c38ULL), (0x46fdfdd3fdbb2ee7ULL), (0x1f4d4d294d52649aULL),
            (0x7692927292e4e039ULL), (0xfa7575c9758fbceaULL), (0x3606061806301e0cULL), (0xae8a8a128a249809ULL),
            (0x4bb2b2f2b2f94079ULL), (0x85e6e6bfe66359d1ULL), (0x7e0e0e380e70361cULL), (0xe71f1f7c1ff8633eULL),
            (0x556262956237f7c4ULL), (0x3ad4d477d4eea3b5ULL), (0x81a8a89aa829324dULL), (0x5296966296c4f431ULL),
            (0x62f9f9c3f99b3aefULL), (0xa3c5c533c566f697ULL), (0x102525942535b14aULL), (0xab59597959f220b2ULL),
            (0xd084842a8454ae15ULL), (0xc57272d572b7a7e4ULL), (0xec3939e439d5dd72ULL), (0x164c4c2d4c5a6198ULL),
            (0x945e5e655eca3bbcULL), (0x9f7878fd78e785f0ULL), (0xe53838e038ddd870ULL), (0x988c8c0a8c148605ULL),
            (0x17d1d163d1c6b2bfULL), (0xe4a5a5aea5410b57ULL), (0xa1e2e2afe2434dd9ULL), (0x4e616199612ff8c2ULL),
            (0x42b3b3f6b3f1457bULL), (0x342121842115a542ULL), (0x089c9c4a9c94d625ULL), (0xee1e1e781ef0663cULL),
            (0x6143431143225286ULL), (0xb1c7c73bc776fc93ULL), (0x4ffcfcd7fcb32be5ULL), (0x2404041004201408ULL),
            (0xe351515951b208a2ULL), (0x2599995e99bcc72fULL), (0x226d6da96d4fc4daULL), (0x650d0d340d68391aULL),
            (0x79fafacffa8335e9ULL), (0x69dfdf5bdfb684a3ULL), (0xa97e7ee57ed79bfcULL), (0x19242490243db448ULL),
            (0xfe3b3bec3bc5d776ULL), (0x9aabab96ab313d4bULL), (0xf0cece1fce3ed181ULL), (0x9911114411885522ULL),
            (0x838f8f068f0c8903ULL), (0x044e4e254e4a6b9cULL), (0x66b7b7e6b7d15173ULL), (0xe0ebeb8beb0b60cbULL),
            (0xc13c3cf03cfdcc78ULL), (0xfd81813e817cbf1fULL), (0x4094946a94d4fe35ULL), (0x1cf7f7fbf7eb0cf3ULL),
            (0x18b9b9deb9a1676fULL), (0x8b13134c13985f26ULL), (0x512c2cb02c7d9c58ULL), (0x05d3d36bd3d6b8bbULL),
            (0x8ce7e7bbe76b5cd3ULL), (0x396e6ea56e57cbdcULL), (0xaac4c437c46ef395ULL), (0x1b03030c03180f06ULL),
            (0xdc565645568a13acULL), (0x5e44440d441a4988ULL), (0xa07f7fe17fdf9efeULL), (0x88a9a99ea921374fULL),
            (0x672a2aa82a4d8254ULL), (0x0abbbbd6bbb16d6bULL), (0x87c1c123c146e29fULL), (0xf153535153a202a6ULL),
            (0x72dcdc57dcae8ba5ULL), (0x530b0b2c0b582716ULL), (0x019d9d4e9d9cd327ULL), (0x2b6c6cad6c47c1d8ULL),
            (0xa43131c43195f562ULL), (0xf37474cd7487b9e8ULL), (0x15f6f6fff6e309f1ULL), (0x4c464605460a438cULL),
            (0xa5acac8aac092645ULL), (0xb589891e893c970fULL), (0xb414145014a04428ULL), (0xbae1e1a3e15b42dfULL),
            (0xa616165816b04e2cULL), (0xf73a3ae83acdd274ULL), (0x066969b9696fd0d2ULL), (0x4109092409482d12ULL),
            (0xd77070dd70a7ade0ULL), (0x6fb6b6e2b6d95471ULL), (0x1ed0d067d0ceb7bdULL), (0xd6eded93ed3b7ec7ULL),
            (0xe2cccc17cc2edb85ULL), (0x68424215422a5784ULL), (0x2c98985a98b4c22dULL), (0xeda4a4aaa4490e55ULL),
            (0x752828a0285d8850ULL), (0x865c5c6d5cda31b8ULL), (0x6bf8f8c7f8933fedULL), (0xc28686228644a411ULL),
        },
        {
            /* C2 vectors */
            (0x30d818186018c078ULL), (0x462623238c2305afULL), (0x91b8c6c63fc67ef9ULL), (0xcdfbe8e887e8136fULL),
            (0x13cb878726874ca1ULL), (0x6d11b8b8dab8a962ULL), (0x0209010104010805ULL), (0x9e0d4f4f214f426eULL),
            (0x6c9b3636d836adeeULL), (0x51ffa6a6a2a65904ULL), (0xb90cd2d26fd2debdULL), (0xf70ef5f5f3f5fb06ULL),
            (0xf2967979f979ef80ULL), (0xde306f6fa16f5fceULL), (0x3f6d91917e91fcefULL), (0xa4f852525552aa07ULL),
            (0xc04760609d6027fdULL), (0x6535bcbccabc8976ULL), (0x2b379b9b569baccdULL), (0x018a8e8e028e048cULL),
            (0x5bd2a3a3b6a37115ULL), (0x186c0c0c300c603cULL), (0xf6847b7bf17bff8aULL), (0x6a803535d435b5e1ULL),
            (0x3af51d1d741de869ULL), (0xddb3e0e0a7e05347ULL), (0xb321d7d77bd7f6acULL), (0x999cc2c22fc25eedULL),
            (0x5c432e2eb82e6d96ULL), (0x96294b4b314b627aULL), (0xe15dfefedffea321ULL), (0xaed5575741578216ULL),
            (0x2abd15155415a841ULL), (0xeee87777c1779fb6ULL), (0x6e923737dc37a5ebULL), (0xd79ee5e5b3e57b56ULL),
            (0x23139f9f469f8cd9ULL), (0xfd23f0f0e7f0d317ULL), (0x94204a4a354a6a7fULL), (0xa944dada4fda9e95ULL),
            (0xb0a258587d58fa25ULL), (0x8fcfc9c903c906caULL), (0x527c2929a429558dULL), (0x145a0a0a280a5022ULL),
            (0x7f50b1b1feb1e14fULL), (0x5dc9a0a0baa0691aULL), (0xd6146b6bb16b7fdaULL), (0x17d985852e855cabULL),
            (0x673cbdbdcebd8173ULL), (0xba8f5d5d695dd234ULL), (0x2090101040108050ULL), (0xf507f4f4f7f4f303ULL),
            (0x8bddcbcb0bcb16c0ULL), (0x7cd33e3ef83eedc6ULL), (0x0a2d050514052811ULL), (0xce78676781671fe6ULL),
            (0xd597e4e4b7e47353ULL), (0x4e0227279c2725bbULL), (0x8273414119413258ULL), (0x0ba78b8b168b2c9dULL),
            (0x53f6a7a7a6a75101ULL), (0xfab27d7de97dcf94ULL), (0x374995956e95dcfbULL), (0xad56d8d847d88e9fULL),
            (0xeb70fbfbcbfb8b30ULL), (0xc1cdeeee9fee2371ULL), (0xf8bb7c7ced7cc791ULL), (0xcc716666856617e3ULL),
            (0xa77bdddd53dda68eULL), (0x2eaf17175c17b84bULL), (0x8e45474701470246ULL), (0x211a9e9e429e84dcULL),
            (0x89d4caca0fca1ec5ULL), (0x5a582d2db42d7599ULL), (0x632ebfbfc6bf9179ULL), (0x0e3f07071c07381bULL),
            (0x47acadad8ead0123ULL), (0xb4b05a5a755aea2fULL), (0x1bef838336836cb5ULL), (0x66b63333cc3385ffULL),
            (0xc65c636391633ff2ULL), (0x041202020802100aULL), (0x4993aaaa92aa3938ULL), (0xe2de7171d971afa8ULL),
            (0x8dc6c8c807c80ecfULL), (0x32d119196419c87dULL), (0x923b494939497270ULL), (0xaf5fd9d943d9869aULL),
            (0xf931f2f2eff2c31dULL), (0xdba8e3e3abe34b48ULL), (0xb6b95b5b715be22aULL), (0x0dbc88881a883492ULL),
            (0x293e9a9a529aa4c8ULL), (0x4c0b262698262dbeULL), (0x64bf3232c8328dfaULL), (0x7d59b0b0fab0e94aULL),
            (0xcff2e9e983e91b6aULL), (0x1e770f0f3c0f7833ULL), (0xb733d5d573d5e6a6ULL), (0x1df480803a8074baULL),
            (0x6127bebec2be997cULL), (0x87ebcdcd13cd26deULL), (0x68893434d034bde4ULL), (0x903248483d487a75ULL),
            (0xe354ffffdbffab24ULL), (0xf48d7a7af57af78fULL), (0x3d6490907a90f4eaULL), (0xbe9d5f5f615fc23eULL),
            (0x403d202080201da0ULL), (0xd00f6868bd6867d5ULL), (0x34ca1a1a681ad072ULL), (0x41b7aeae82ae192cULL),
            (0x757db4b4eab4c95eULL), (0xa8ce54544d549a19ULL), (0x3b7f93937693ece5ULL), (0x442f222288220daaULL),
            (0xc86364648d6407e9ULL), (0xff2af1f1e3f1db12ULL), (0xe6cc7373d173bfa2ULL), (0x248212124812905aULL),
            (0x807a40401d403a5dULL), (0x1048080820084028ULL), (0x9b95c3c32bc356e8ULL), (0xc5dfecec97ec337bULL),
            (0xab4ddbdb4bdb9690ULL), (0x5fc0a1a1bea1611fULL), (0x07918d8d0e8d1c83ULL), (0x7ac83d3df43df5c9ULL),
            (0x335b97976697ccf1ULL), (0x0000000000000000ULL), (0x83f9cfcf1bcf36d4ULL), (0x566e2b2bac2b4587ULL),
            (0xece17676c57697b3ULL), (0x19e68282328264b0ULL), (0xb128d6d67fd6fea9ULL), (0x36c31b1b6c1bd877ULL),
            (0x7774b5b5eeb5c15bULL), (0x43beafaf86af1129ULL), (0xd41d6a6ab56a77dfULL), (0xa0ea50505d50ba0dULL),
            (0x8a5745450945124cULL), (0xfb38f3f3ebf3cb18ULL), (0x60ad3030c0309df0ULL), (0xc3c4efef9bef2b74ULL),
            (0x7eda3f3ffc3fe5c3ULL), (0xaac755554955921cULL), (0x59dba2a2b2a27910ULL), (0xc9e9eaea8fea0365ULL),
            (0xca6a656589650fecULL), (0x6903babad2bab968ULL), (0x5e4a2f2fbc2f6593ULL), (0x9d8ec0c027c04ee7ULL),
            (0xa160dede5fdebe81ULL), (0x38fc1c1c701ce06cULL), (0xe746fdfdd3fdbb2eULL), (0x9a1f4d4d294d5264ULL),
            (0x397692927292e4e0ULL), (0xeafa7575c9758fbcULL), (0x0c3606061806301eULL), (0x09ae8a8a128a2498ULL),
            (0x794bb2b2f2b2f940ULL), (0xd185e6e6bfe66359ULL), (0x1c7e0e0e380e7036ULL), (0x3ee71f1f7c1ff863ULL),
            (0xc4556262956237f7ULL), (0xb53ad4d477d4eea3ULL), (0x4d81a8a89aa82932ULL), (0x315296966296c4f4ULL),
            (0xef62f9f9c3f99b3aULL), (0x97a3c5c533c566f6ULL), (0x4a102525942535b1ULL), (0xb2ab59597959f220ULL),
            (0x15d084842a8454aeULL), (0xe4c57272d572b7a7ULL), (0x72ec3939e439d5ddULL), (0x98164c4c2d4c5a61ULL),
            (0xbc945e5e655eca3bULL), (0xf09f7878fd78e785ULL), (0x70e53838e038ddd8ULL), (0x05988c8c0a8c1486ULL),
            (0xbf17d1d163d1c6b2ULL), (0x57e4a5a5aea5410bULL), (0xd9a1e2e2afe2434dULL), (0xc24e616199612ff8ULL),
            (0x7b42b3b3f6b3f145ULL), (0x42342121842115a5ULL), (0x25089c9c4a9c94d6ULL), (0x3cee1e1e781ef066ULL),
            (0x8661434311432252ULL), (0x93b1c7c73bc776fcULL), (0xe54ffcfcd7fcb32bULL), (0x0824040410042014ULL),
            (0xa2e351515951b208ULL), (0x2f2599995e99bcc7ULL), (0xda226d6da96d4fc4ULL), (0x1a650d0d340d6839ULL),
            (0xe979fafacffa8335ULL), (0xa369dfdf5bdfb684ULL), (0xfca97e7ee57ed79bULL), (0x4819242490243db4ULL),
            (0x76fe3b3bec3bc5d7ULL), (0x4b9aabab96ab313dULL), (0x81f0cece1fce3ed1ULL), (0x2299111144118855ULL),
            (0x03838f8f068f0c89ULL), (0x9c044e4e254e4a6bULL), (0x7366b7b7e6b7d151ULL), (0xcbe0ebeb8beb0b60ULL),
            (0x78c13c3cf03cfdccULL), (0x1ffd81813e817cbfULL), (0x354094946a94d4feULL), (0xf31cf7f7fbf7eb0cULL),
            (0x6f18b9b9deb9a167ULL), (0x268b13134c13985fULL), (0x58512c2cb02c7d9cULL), (0xbb05d3d36bd3d6b8ULL),
            (0xd38ce7e7bbe76b5cULL), (0xdc396e6ea56e57cbULL), (0x95aac4c437c46ef3ULL), (0x061b03030c03180fULL),
            (0xacdc565645568a13ULL), (0x885e44440d441a49ULL), (0xfea07f7fe17fdf9eULL), (0x4f88a9a99ea92137ULL),
            (0x54672a2aa82a4d82ULL), (0x6b0abbbbd6bbb16dULL), (0x9f87c1c123c146e2ULL), (0xa6f153535153a202ULL),
            (0xa572dcdc57dcae8bULL), (0x16530b0b2c0b5827ULL), (0x27019d9d4e9d9cd3ULL), (0xd82b6c6cad6c47c1ULL),
            (0x62a43131c43195f5ULL), (0xe8f37474cd7487b9ULL), (0xf115f6f6fff6e309ULL), (0x8c4c464605460a43ULL),
            (0x45a5acac8aac0926ULL), (0x0fb589891e893c97ULL), (0x28b414145014a044ULL), (0xdfbae1e1a3e15b42ULL),
            (0x2ca616165816b04eULL), (0x74f73a3ae83acdd2ULL), (0xd2066969b9696fd0ULL), (0x124109092409482dULL),
            (0xe0d77070dd70a7adULL), (0x716fb6b6e2b6d954ULL), (0xbd1ed0d067d0ceb7ULL), (0xc7d6eded93ed3b7eULL),
            (0x85e2cccc17cc2edbULL), (0x8468424215422a57ULL), (0x2d2c98985a98b4c2ULL), (0x55eda4a4aaa4490eULL),
            (0x50752828a0285d88ULL), (0xb8865c5c6d5cda31ULL), (0xed6bf8f8c7f8933fULL), (0x11c28686228644a4ULL),
        },
        {
            /* C3 vectors */
            (0x7830d818186018c0ULL), (0xaf462623238c2305ULL), (0xf991b8c6c63fc67eULL), (0x6fcdfbe8e887e813ULL),
            (0xa113cb878726874cULL), (0x626d11b8b8dab8a9ULL), (0x0502090101040108ULL), (0x6e9e0d4f4f214f42ULL),
            (0xee6c9b3636d836adULL), (0x0451ffa6a6a2a659ULL), (0xbdb90cd2d26fd2deULL), (0x06f70ef5f5f3f5fbULL),
            (0x80f2967979f979efULL), (0xcede306f6fa16f5fULL), (0xef3f6d91917e91fcULL), (0x07a4f852525552aaULL),
            (0xfdc04760609d6027ULL), (0x766535bcbccabc89ULL), (0xcd2b379b9b569bacULL), (0x8c018a8e8e028e04ULL),
            (0x155bd2a3a3b6a371ULL), (0x3c186c0c0c300c60ULL), (0x8af6847b7bf17bffULL), (0xe16a803535d435b5ULL),
            (0x693af51d1d741de8ULL), (0x47ddb3e0e0a7e053ULL), (0xacb321d7d77bd7f6ULL), (0xed999cc2c22fc25eULL),
            (0x965c432e2eb82e6dULL), (0x7a96294b4b314b62ULL), (0x21e15dfefedffea3ULL), (0x16aed55757415782ULL),
            (0x412abd15155415a8ULL), (0xb6eee87777c1779fULL), (0xeb6e923737dc37a5ULL), (0x56d79ee5e5b3e57bULL),
            (0xd923139f9f469f8cULL), (0x17fd23f0f0e7f0d3ULL), (0x7f94204a4a354a6aULL), (0x95a944dada4fda9eULL),
            (0x25b0a258587d58faULL), (0xca8fcfc9c903c906ULL), (0x8d527c2929a42955ULL), (0x22145a0a0a280a50ULL),
            (0x4f7f50b1b1feb1e1ULL), (0x1a5dc9a0a0baa069ULL), (0xdad6146b6bb16b7fULL), (0xab17d985852e855cULL),
            (0x73673cbdbdcebd81ULL), (0x34ba8f5d5d695dd2ULL), (0x5020901010401080ULL), (0x03f507f4f4f7f4f3ULL),
            (0xc08bddcbcb0bcb16ULL), (0xc67cd33e3ef83eedULL), (0x110a2d0505140528ULL), (0xe6ce78676781671fULL),
            (0x53d597e4e4b7e473ULL), (0xbb4e0227279c2725ULL), (0x5882734141194132ULL), (0x9d0ba78b8b168b2cULL),
            (0x0153f6a7a7a6a751ULL), (0x94fab27d7de97dcfULL), (0xfb374995956e95dcULL), (0x9fad56d8d847d88eULL),
            (0x30eb70fbfbcbfb8bULL), (0x71c1cdeeee9fee23ULL), (0x91f8bb7c7ced7cc7ULL), (0xe3cc716666856617ULL),
            (0x8ea77bdddd53dda6ULL), (0x4b2eaf17175c17b8ULL), (0x468e454747014702ULL), (0xdc211a9e9e429e84ULL),
            (0xc589d4caca0fca1eULL), (0x995a582d2db42d75ULL), (0x79632ebfbfc6bf91ULL), (0x1b0e3f07071c0738ULL),
            (0x2347acadad8ead01ULL), (0x2fb4b05a5a755aeaULL), (0xb51bef838336836cULL), (0xff66b63333cc3385ULL),
            (0xf2c65c636391633fULL), (0x0a04120202080210ULL), (0x384993aaaa92aa39ULL), (0xa8e2de7171d971afULL),
            (0xcf8dc6c8c807c80eULL), (0x7d32d119196419c8ULL), (0x70923b4949394972ULL), (0x9aaf5fd9d943d986ULL),
            (0x1df931f2f2eff2c3ULL), (0x48dba8e3e3abe34bULL), (0x2ab6b95b5b715be2ULL), (0x920dbc88881a8834ULL),
            (0xc8293e9a9a529aa4ULL), (0xbe4c0b262698262dULL), (0xfa64bf3232c8328dULL), (0x4a7d59b0b0fab0e9ULL),
            (0x6acff2e9e983e91bULL), (0x331e770f0f3c0f78ULL), (0xa6b733d5d573d5e6ULL), (0xba1df480803a8074ULL),
            (0x7c6127bebec2be99ULL), (0xde87ebcdcd13cd26ULL), (0xe468893434d034bdULL), (0x75903248483d487aULL),
            (0x24e354ffffdbffabULL), (0x8ff48d7a7af57af7ULL), (0xea3d6490907a90f4ULL), (0x3ebe9d5f5f615fc2ULL),
            (0xa0403d202080201dULL), (0xd5d00f6868bd6867ULL), (0x7234ca1a1a681ad0ULL), (0x2c41b7aeae82ae19ULL),
            (0x5e757db4b4eab4c9ULL), (0x19a8ce54544d549aULL), (0xe53b7f93937693ecULL), (0xaa442f222288220dULL),
            (0xe9c86364648d6407ULL), (0x12ff2af1f1e3f1dbULL), (0xa2e6cc7373d173bfULL), (0x5a24821212481290ULL),
            (0x5d807a40401d403aULL), (0x2810480808200840ULL), (0xe89b95c3c32bc356ULL), (0x7bc5dfecec97ec33ULL),
            (0x90ab4ddbdb4bdb96ULL), (0x1f5fc0a1a1bea161ULL), (0x8307918d8d0e8d1cULL), (0xc97ac83d3df43df5ULL),
            (0xf1335b97976697ccULL), (0x0000000000000000ULL), (0xd483f9cfcf1bcf36ULL), (0x87566e2b2bac2b45ULL),
            (0xb3ece17676c57697ULL), (0xb019e68282328264ULL), (0xa9b128d6d67fd6feULL), (0x7736c31b1b6c1bd8ULL),
            (0x5b7774b5b5eeb5c1ULL), (0x2943beafaf86af11ULL), (0xdfd41d6a6ab56a77ULL), (0x0da0ea50505d50baULL),
            (0x4c8a574545094512ULL), (0x18fb38f3f3ebf3cbULL), (0xf060ad3030c0309dULL), (0x74c3c4efef9bef2bULL),
            (0xc37eda3f3ffc3fe5ULL), (0x1caac75555495592ULL), (0x1059dba2a2b2a279ULL), (0x65c9e9eaea8fea03ULL),
            (0xecca6a656589650fULL), (0x686903babad2bab9ULL), (0x935e4a2f2fbc2f65ULL), (0xe79d8ec0c027c04eULL),
            (0x81a160dede5fdebeULL), (0x6c38fc1c1c701ce0ULL), (0x2ee746fdfdd3fdbbULL), (0x649a1f4d4d294d52ULL),
            (0xe0397692927292e4ULL), (0xbceafa7575c9758fULL), (0x1e0c360606180630ULL), (0x9809ae8a8a128a24ULL),
            (0x40794bb2b2f2b2f9ULL), (0x59d185e6e6bfe663ULL), (0x361c7e0e0e380e70ULL), (0x633ee71f1f7c1ff8ULL),
            (0xf7c4556262956237ULL), (0xa3b53ad4d477d4eeULL), (0x324d81a8a89aa829ULL), (0xf4315296966296c4ULL),
            (0x3aef62f9f9c3f99bULL), (0xf697a3c5c533c566ULL), (0xb14a102525942535ULL), (0x20b2ab59597959f2ULL),
            (0xae15d084842a8454ULL), (0xa7e4c57272d572b7ULL), (0xdd72ec3939e439d5ULL), (0x6198164c4c2d4c5aULL),
            (0x3bbc945e5e655ecaULL), (0x85f09f7878fd78e7ULL), (0xd870e53838e038ddULL), (0x8605988c8c0a8c14ULL),
            (0xb2bf17d1d163d1c6ULL), (0x0b57e4a5a5aea541ULL), (0x4dd9a1e2e2afe243ULL), (0xf8c24e616199612fULL),
            (0x457b42b3b3f6b3f1ULL), (0xa542342121842115ULL), (0xd625089c9c4a9c94ULL), (0x663cee1e1e781ef0ULL),
            (0x5286614343114322ULL), (0xfc93b1c7c73bc776ULL), (0x2be54ffcfcd7fcb3ULL), (0x1408240404100420ULL),
            (0x08a2e351515951b2ULL), (0xc72f2599995e99bcULL), (0xc4da226d6da96d4fULL), (0x391a650d0d340d68ULL),
            (0x35e979fafacffa83ULL), (0x84a369dfdf5bdfb6ULL), (0x9bfca97e7ee57ed7ULL), (0xb44819242490243dULL),
            (0xd776fe3b3bec3bc5ULL), (0x3d4b9aabab96ab31ULL), (0xd181f0cece1fce3eULL), (0x5522991111441188ULL),
            (0x8903838f8f068f0cULL), (0x6b9c044e4e254e4aULL), (0x517366b7b7e6b7d1ULL), (0x60cbe0ebeb8beb0bULL),
            (0xcc78c13c3cf03cfdULL), (0xbf1ffd81813e817cULL), (0xfe354094946a94d4ULL), (0x0cf31cf7f7fbf7ebULL),
            (0x676f18b9b9deb9a1ULL), (0x5f268b13134c1398ULL), (0x9c58512c2cb02c7dULL), (0xb8bb05d3d36bd3d6ULL),
            (0x5cd38ce7e7bbe76bULL), (0xcbdc396e6ea56e57ULL), (0xf395aac4c437c46eULL), (0x0f061b03030c0318ULL),
            (0x13acdc565645568aULL), (0x49885e44440d441aULL), (0x9efea07f7fe17fdfULL), (0x374f88a9a99ea921ULL),
            (0x8254672a2aa82a4dULL), (0x6d6b0abbbbd6bbb1ULL), (0xe29f87c1c123c146ULL), (0x02a6f153535153a2ULL),
            (0x8ba572dcdc57dcaeULL), (0x2716530b0b2c0b58ULL), (0xd327019d9d4e9d9cULL), (0xc1d82b6c6cad6c47ULL),
            (0xf562a43131c43195ULL), (0xb9e8f37474cd7487ULL), (0x09f115f6f6fff6e3ULL), (0x438c4c464605460aULL),
            (0x2645a5acac8aac09ULL), (0x970fb589891e893cULL), (0x4428b414145014a0ULL), (0x42dfbae1e1a3e15bULL),
            (0x4e2ca616165816b0ULL), (0xd274f73a3ae83acdULL), (0xd0d2066969b9696fULL), (0x2d12410909240948ULL),
            (0xade0d77070dd70a7ULL), (0x54716fb6b6e2b6d9ULL), (0xb7bd1ed0d067d0ceULL), (0x7ec7d6eded93ed3bULL),
            (0xdb85e2cccc17cc2eULL), (0x578468424215422aULL), (0xc22d2c98985a98b4ULL), (0x0e55eda4a4aaa449ULL),
            (0x8850752828a0285dULL), (0x31b8865c5c6d5cdaULL), (0x3fed6bf8f8c7f893ULL), (0xa411c28686228644ULL),
        },
        {
            /* C4 vectors */
            (0xc07830d818186018ULL), (0x05af462623238c23ULL), (0x7ef991b8c6c63fc6ULL), (0x136fcdfbe8e887e8ULL),
            (0x4ca113cb87872687ULL), (0xa9626d11b8b8dab8ULL), (0x0805020901010401ULL), (0x426e9e0d4f4f214fULL),
            (0xadee6c9b3636d836ULL), (0x590451ffa6a6a2a6ULL), (0xdebdb90cd2d26fd2ULL), (0xfb06f70ef5f5f3f5ULL),
            (0xef80f2967979f979ULL), (0x5fcede306f6fa16fULL), (0xfcef3f6d91917e91ULL), (0xaa07a4f852525552ULL),
            (0x27fdc04760609d60ULL), (0x89766535bcbccabcULL), (0xaccd2b379b9b569bULL), (0x048c018a8e8e028eULL),
            (0x71155bd2a3a3b6a3ULL), (0x603c186c0c0c300cULL), (0xff8af6847b7bf17bULL), (0xb5e16a803535d435ULL),
            (0xe8693af51d1d741dULL), (0x5347ddb3e0e0a7e0ULL), (0xf6acb321d7d77bd7ULL), (0x5eed999cc2c22fc2ULL),
            (0x6d965c432e2eb82eULL), (0x627a96294b4b314bULL), (0xa321e15dfefedffeULL), (0x8216aed557574157ULL),
            (0xa8412abd15155415ULL), (0x9fb6eee87777c177ULL), (0xa5eb6e923737dc37ULL), (0x7b56d79ee5e5b3e5ULL),
            (0x8cd923139f9f469fULL), (0xd317fd23f0f0e7f0ULL), (0x6a7f94204a4a354aULL), (0x9e95a944dada4fdaULL),
            (0xfa25b0a258587d58ULL), (0x06ca8fcfc9c903c9ULL), (0x558d527c2929a429ULL), (0x5022145a0a0a280aULL),
            (0xe14f7f50b1b1feb1ULL), (0x691a5dc9a0a0baa0ULL), (0x7fdad6146b6bb16bULL), (0x5cab17d985852e85ULL),
            (0x8173673cbdbdcebdULL), (0xd234ba8f5d5d695dULL), (0x8050209010104010ULL), (0xf303f507f4f4f7f4ULL),
            (0x16c08bddcbcb0bcbULL), (0xedc67cd33e3ef83eULL), (0x28110a2d05051405ULL), (0x1fe6ce7867678167ULL),
            (0x7353d597e4e4b7e4ULL), (0x25bb4e0227279c27ULL), (0x3258827341411941ULL), (0x2c9d0ba78b8b168bULL),
            (0x510153f6a7a7a6a7ULL), (0xcf94fab27d7de97dULL), (0xdcfb374995956e95ULL), (0x8e9fad56d8d847d8ULL),
            (0x8b30eb70fbfbcbfbULL), (0x2371c1cdeeee9feeULL), (0xc791f8bb7c7ced7cULL), (0x17e3cc7166668566ULL),
            (0xa68ea77bdddd53ddULL), (0xb84b2eaf17175c17ULL), (0x02468e4547470147ULL), (0x84dc211a9e9e429eULL),
            (0x1ec589d4caca0fcaULL), (0x75995a582d2db42dULL), (0x9179632ebfbfc6bfULL), (0x381b0e3f07071c07ULL),
            (0x012347acadad8eadULL), (0xea2fb4b05a5a755aULL), (0x6cb51bef83833683ULL), (0x85ff66b63333cc33ULL),
            (0x3ff2c65c63639163ULL), (0x100a041202020802ULL), (0x39384993aaaa92aaULL), (0xafa8e2de7171d971ULL),
            (0x0ecf8dc6c8c807c8ULL), (0xc87d32d119196419ULL), (0x7270923b49493949ULL), (0x869aaf5fd9d943d9ULL),
            (0xc31df931f2f2eff2ULL), (0x4b48dba8e3e3abe3ULL), (0xe22ab6b95b5b715bULL), (0x34920dbc88881a88ULL),
            (0xa4c8293e9a9a529aULL), (0x2dbe4c0b26269826ULL), (0x8dfa64bf3232c832ULL), (0xe94a7d59b0b0fab0ULL),
            (0x1b6acff2e9e983e9ULL), (0x78331e770f0f3c0fULL), (0xe6a6b733d5d573d5ULL), (0x74ba1df480803a80ULL),
            (0x997c6127bebec2beULL), (0x26de87ebcdcd13cdULL), (0xbde468893434d034ULL), (0x7a75903248483d48ULL),
            (0xab24e354ffffdbffULL), (0xf78ff48d7a7af57aULL), (0xf4ea3d6490907a90ULL), (0xc23ebe9d5f5f615fULL),
            (0x1da0403d20208020ULL), (0x67d5d00f6868bd68ULL), (0xd07234ca1a1a681aULL), (0x192c41b7aeae82aeULL),
            (0xc95e757db4b4eab4ULL), (0x9a19a8ce54544d54ULL), (0xece53b7f93937693ULL), (0x0daa442f22228822ULL),
            (0x07e9c86364648d64ULL), (0xdb12ff2af1f1e3f1ULL), (0xbfa2e6cc7373d173ULL), (0x905a248212124812ULL),
            (0x3a5d807a40401d40ULL), (0x4028104808082008ULL), (0x56e89b95c3c32bc3ULL), (0x337bc5dfecec97ecULL),
            (0x9690ab4ddbdb4bdbULL), (0x611f5fc0a1a1bea1ULL), (0x1c8307918d8d0e8dULL), (0xf5c97ac83d3df43dULL),
            (0xccf1335b97976697ULL), (0x0000000000000000ULL), (0x36d483f9cfcf1bcfULL), (0x4587566e2b2bac2bULL),
            (0x97b3ece17676c576ULL), (0x64b019e682823282ULL), (0xfea9b128d6d67fd6ULL), (0xd87736c31b1b6c1bULL),
            (0xc15b7774b5b5eeb5ULL), (0x112943beafaf86afULL), (0x77dfd41d6a6ab56aULL), (0xba0da0ea50505d50ULL),
            (0x124c8a5745450945ULL), (0xcb18fb38f3f3ebf3ULL), (0x9df060ad3030c030ULL), (0x2b74c3c4efef9befULL),
            (0xe5c37eda3f3ffc3fULL), (0x921caac755554955ULL), (0x791059dba2a2b2a2ULL), (0x0365c9e9eaea8feaULL),
            (0x0fecca6a65658965ULL), (0xb9686903babad2baULL), (0x65935e4a2f2fbc2fULL), (0x4ee79d8ec0c027c0ULL),
            (0xbe81a160dede5fdeULL), (0xe06c38fc1c1c701cULL), (0xbb2ee746fdfdd3fdULL), (0x52649a1f4d4d294dULL),
            (0xe4e0397692927292ULL), (0x8fbceafa7575c975ULL), (0x301e0c3606061806ULL), (0x249809ae8a8a128aULL),
            (0xf940794bb2b2f2b2ULL), (0x6359d185e6e6bfe6ULL), (0x70361c7e0e0e380eULL), (0xf8633ee71f1f7c1fULL),
            (0x37f7c45562629562ULL), (0xeea3b53ad4d477d4ULL), (0x29324d81a8a89aa8ULL), (0xc4f4315296966296ULL),
            (0x9b3aef62f9f9c3f9ULL), (0x66f697a3c5c533c5ULL), (0x35b14a1025259425ULL), (0xf220b2ab59597959ULL),
            (0x54ae15d084842a84ULL), (0xb7a7e4c57272d572ULL), (0xd5dd72ec3939e439ULL), (0x5a6198164c4c2d4cULL),
            (0xca3bbc945e5e655eULL), (0xe785f09f7878fd78ULL), (0xddd870e53838e038ULL), (0x148605988c8c0a8cULL),
            (0xc6b2bf17d1d163d1ULL), (0x410b57e4a5a5aea5ULL), (0x434dd9a1e2e2afe2ULL), (0x2ff8c24e61619961ULL),
            (0xf1457b42b3b3f6b3ULL), (0x15a5423421218421ULL), (0x94d625089c9c4a9cULL), (0xf0663cee1e1e781eULL),
            (0x2252866143431143ULL), (0x76fc93b1c7c73bc7ULL), (0xb32be54ffcfcd7fcULL), (0x2014082404041004ULL),
            (0xb208a2e351515951ULL), (0xbcc72f2599995e99ULL), (0x4fc4da226d6da96dULL), (0x68391a650d0d340dULL),
            (0x8335e979fafacffaULL), (0xb684a369dfdf5bdfULL), (0xd79bfca97e7ee57eULL), (0x3db4481924249024ULL),
            (0xc5d776fe3b3bec3bULL), (0x313d4b9aabab96abULL), (0x3ed181f0cece1fceULL), (0x8855229911114411ULL),
            (0x0c8903838f8f068fULL), (0x4a6b9c044e4e254eULL), (0xd1517366b7b7e6b7ULL), (0x0b60cbe0ebeb8bebULL),
            (0xfdcc78c13c3cf03cULL), (0x7cbf1ffd81813e81ULL), (0xd4fe354094946a94ULL), (0xeb0cf31cf7f7fbf7ULL),
            (0xa1676f18b9b9deb9ULL), (0x985f268b13134c13ULL), (0x7d9c58512c2cb02cULL), (0xd6b8bb05d3d36bd3ULL),
            (0x6b5cd38ce7e7bbe7ULL), (0x57cbdc396e6ea56eULL), (0x6ef395aac4c437c4ULL), (0x180f061b03030c03ULL),
            (0x8a13acdc56564556ULL), (0x1a49885e44440d44ULL), (0xdf9efea07f7fe17fULL), (0x21374f88a9a99ea9ULL),
            (0x4d8254672a2aa82aULL), (0xb16d6b0abbbbd6bbULL), (0x46e29f87c1c123c1ULL), (0xa202a6f153535153ULL),
            (0xae8ba572dcdc57dcULL), (0x582716530b0b2c0bULL), (0x9cd327019d9d4e9dULL), (0x47c1d82b6c6cad6cULL),
            (0x95f562a43131c431ULL), (0x87b9e8f37474cd74ULL), (0xe309f115f6f6fff6ULL), (0x0a438c4c46460546ULL),
            (0x092645a5acac8aacULL), (0x3c970fb589891e89ULL), (0xa04428b414145014ULL), (0x5b42dfbae1e1a3e1ULL),
            (0xb04e2ca616165816ULL), (0xcdd274f73a3ae83aULL), (0x6fd0d2066969b969ULL), (0x482d124109092409ULL),
            (0xa7ade0d77070dd70ULL), (0xd954716fb6b6e2b6ULL), (0xceb7bd1ed0d067d0ULL), (0x3b7ec7d6eded93edULL),
            (0x2edb85e2cccc17ccULL), (0x2a57846842421542ULL), (0xb4c22d2c98985a98ULL), (0x490e55eda4a4aaa4ULL),
            (0x5d8850752828a028ULL), (0xda31b8865c5c6d5cULL), (0x933fed6bf8f8c7f8ULL), (0x44a411c286862286ULL),
        },
        {
            /* C5 vectors */
            (0x18c07830d8181860ULL), (0x2305af462623238cULL), (0xc67ef991b8c6c63fULL), (0xe8136fcdfbe8e887ULL),
            (0x874ca113cb878726ULL), (0xb8a9626d11b8b8daULL), (0x0108050209010104ULL), (0x4f426e9e0d4f4f21ULL),
            (0x36adee6c9b3636d8ULL), (0xa6590451ffa6a6a2ULL), (0xd2debdb90cd2d26fULL), (0xf5fb06f70ef5f5f3ULL),
            (0x79ef80f2967979f9ULL), (0x6f5fcede306f6fa1ULL), (0x91fcef3f6d91917eULL), (0x52aa07a4f8525255ULL),
            (0x6027fdc04760609dULL), (0xbc89766535bcbccaULL), (0x9baccd2b379b9b56ULL), (0x8e048c018a8e8e02ULL),
            (0xa371155bd2a3a3b6ULL), (0x0c603c186c0c0c30ULL), (0x7bff8af6847b7bf1ULL), (0x35b5e16a803535d4ULL),
            (0x1de8693af51d1d74ULL), (0xe05347ddb3e0e0a7ULL), (0xd7f6acb321d7d77bULL), (0xc25eed999cc2c22fULL),
            (0x2e6d965c432e2eb8ULL), (0x4b627a96294b4b31ULL), (0xfea321e15dfefedfULL), (0x578216aed5575741ULL),
            (0x15a8412abd151554ULL), (0x779fb6eee87777c1ULL), (0x37a5eb6e923737dcULL), (0xe57b56d79ee5e5b3ULL),
            (0x9f8cd923139f9f46ULL), (0xf0d317fd23f0f0e7ULL), (0x4a6a7f94204a4a35ULL), (0xda9e95a944dada4fULL),
            (0x58fa25b0a258587dULL), (0xc906ca8fcfc9c903ULL), (0x29558d527c2929a4ULL), (0x0a5022145a0a0a28ULL),
            (0xb1e14f7f50b1b1feULL), (0xa0691a5dc9a0a0baULL), (0x6b7fdad6146b6bb1ULL), (0x855cab17d985852eULL),
            (0xbd8173673cbdbdceULL), (0x5dd234ba8f5d5d69ULL), (0x1080502090101040ULL), (0xf4f303f507f4f4f7ULL),
            (0xcb16c08bddcbcb0bULL), (0x3eedc67cd33e3ef8ULL), (0x0528110a2d050514ULL), (0x671fe6ce78676781ULL),
            (0xe47353d597e4e4b7ULL), (0x2725bb4e0227279cULL), (0x4132588273414119ULL), (0x8b2c9d0ba78b8b16ULL),
            (0xa7510153f6a7a7a6ULL), (0x7dcf94fab27d7de9ULL), (0x95dcfb374995956eULL), (0xd88e9fad56d8d847ULL),
            (0xfb8b30eb70fbfbcbULL), (0xee2371c1cdeeee9fULL), (0x7cc791f8bb7c7cedULL), (0x6617e3cc71666685ULL),
            (0xdda68ea77bdddd53ULL), (0x17b84b2eaf17175cULL), (0x4702468e45474701ULL), (0x9e84dc211a9e9e42ULL),
            (0xca1ec589d4caca0fULL), (0x2d75995a582d2db4ULL), (0xbf9179632ebfbfc6ULL), (0x07381b0e3f07071cULL),
            (0xad012347acadad8eULL), (0x5aea2fb4b05a5a75ULL), (0x836cb51bef838336ULL), (0x3385ff66b63333ccULL),
            (0x633ff2c65c636391ULL), (0x02100a0412020208ULL), (0xaa39384993aaaa92ULL), (0x71afa8e2de7171d9ULL),
            (0xc80ecf8dc6c8c807ULL), (0x19c87d32d1191964ULL), (0x497270923b494939ULL), (0xd9869aaf5fd9d943ULL),
            (0xf2c31df931f2f2efULL), (0xe34b48dba8e3e3abULL), (0x5be22ab6b95b5b71ULL), (0x8834920dbc88881aULL),
            (0x9aa4c8293e9a9a52ULL), (0x262dbe4c0b262698ULL), (0x328dfa64bf3232c8ULL), (0xb0e94a7d59b0b0faULL),
            (0xe91b6acff2e9e983ULL), (0x0f78331e770f0f3cULL), (0xd5e6a6b733d5d573ULL), (0x8074ba1df480803aULL),
            (0xbe997c6127bebec2ULL), (0xcd26de87ebcdcd13ULL), (0x34bde468893434d0ULL), (0x487a75903248483dULL),
            (0xffab24e354ffffdbULL), (0x7af78ff48d7a7af5ULL), (0x90f4ea3d6490907aULL), (0x5fc23ebe9d5f5f61ULL),
            (0x201da0403d202080ULL), (0x6867d5d00f6868bdULL), (0x1ad07234ca1a1a68ULL), (0xae192c41b7aeae82ULL),
            (0xb4c95e757db4b4eaULL), (0x549a19a8ce54544dULL), (0x93ece53b7f939376ULL), (0x220daa442f222288ULL),
            (0x6407e9c86364648dULL), (0xf1db12ff2af1f1e3ULL), (0x73bfa2e6cc7373d1ULL), (0x12905a2482121248ULL),
            (0x403a5d807a40401dULL), (0x0840281048080820ULL), (0xc356e89b95c3c32bULL), (0xec337bc5dfecec97ULL),
            (0xdb9690ab4ddbdb4bULL), (0xa1611f5fc0a1a1beULL), (0x8d1c8307918d8d0eULL), (0x3df5c97ac83d3df4ULL),
            (0x97ccf1335b979766ULL), (0x0000000000000000ULL), (0xcf36d483f9cfcf1bULL), (0x2b4587566e2b2bacULL),
            (0x7697b3ece17676c5ULL), (0x8264b019e6828232ULL), (0xd6fea9b128d6d67fULL), (0x1bd87736c31b1b6cULL),
            (0xb5c15b7774b5b5eeULL), (0xaf112943beafaf86ULL), (0x6a77dfd41d6a6ab5ULL), (0x50ba0da0ea50505dULL),
            (0x45124c8a57454509ULL), (0xf3cb18fb38f3f3ebULL), (0x309df060ad3030c0ULL), (0xef2b74c3c4efef9bULL),
            (0x3fe5c37eda3f3ffcULL), (0x55921caac7555549ULL), (0xa2791059dba2a2b2ULL), (0xea0365c9e9eaea8fULL),
            (0x650fecca6a656589ULL), (0xbab9686903babad2ULL), (0x2f65935e4a2f2fbcULL), (0xc04ee79d8ec0c027ULL),
            (0xdebe81a160dede5fULL), (0x1ce06c38fc1c1c70ULL), (0xfdbb2ee746fdfdd3ULL), (0x4d52649a1f4d4d29ULL),
            (0x92e4e03976929272ULL), (0x758fbceafa7575c9ULL), (0x06301e0c36060618ULL), (0x8a249809ae8a8a12ULL),
            (0xb2f940794bb2b2f2ULL), (0xe66359d185e6e6bfULL), (0x0e70361c7e0e0e38ULL), (0x1ff8633ee71f1f7cULL),
            (0x6237f7c455626295ULL), (0xd4eea3b53ad4d477ULL), (0xa829324d81a8a89aULL), (0x96c4f43152969662ULL),
            (0xf99b3aef62f9f9c3ULL), (0xc566f697a3c5c533ULL), (0x2535b14a10252594ULL), (0x59f220b2ab595979ULL),
            (0x8454ae15d084842aULL), (0x72b7a7e4c57272d5ULL), (0x39d5dd72ec3939e4ULL), (0x4c5a6198164c4c2dULL),
            (0x5eca3bbc945e5e65ULL), (0x78e785f09f7878fdULL), (0x38ddd870e53838e0ULL), (0x8c148605988c8c0aULL),
            (0xd1c6b2bf17d1d163ULL), (0xa5410b57e4a5a5aeULL), (0xe2434dd9a1e2e2afULL), (0x612ff8c24e616199ULL),
            (0xb3f1457b42b3b3f6ULL), (0x2115a54234212184ULL), (0x9c94d625089c9c4aULL), (0x1ef0663cee1e1e78ULL),
            (0x4322528661434311ULL), (0xc776fc93b1c7c73bULL), (0xfcb32be54ffcfcd7ULL), (0x0420140824040410ULL),
            (0x51b208a2e3515159ULL), (0x99bcc72f2599995eULL), (0x6d4fc4da226d6da9ULL), (0x0d68391a650d0d34ULL),
            (0xfa8335e979fafacfULL), (0xdfb684a369dfdf5bULL), (0x7ed79bfca97e7ee5ULL), (0x243db44819242490ULL),
            (0x3bc5d776fe3b3becULL), (0xab313d4b9aabab96ULL), (0xce3ed181f0cece1fULL), (0x1188552299111144ULL),
            (0x8f0c8903838f8f06ULL), (0x4e4a6b9c044e4e25ULL), (0xb7d1517366b7b7e6ULL), (0xeb0b60cbe0ebeb8bULL),
            (0x3cfdcc78c13c3cf0ULL), (0x817cbf1ffd81813eULL), (0x94d4fe354094946aULL), (0xf7eb0cf31cf7f7fbULL),
            (0xb9a1676f18b9b9deULL), (0x13985f268b13134cULL), (0x2c7d9c58512c2cb0ULL), (0xd3d6b8bb05d3d36bULL),
            (0xe76b5cd38ce7e7bbULL), (0x6e57cbdc396e6ea5ULL), (0xc46ef395aac4c437ULL), (0x03180f061b03030cULL),
            (0x568a13acdc565645ULL), (0x441a49885e44440dULL), (0x7fdf9efea07f7fe1ULL), (0xa921374f88a9a99eULL),
            (0x2a4d8254672a2aa8ULL), (0xbbb16d6b0abbbbd6ULL), (0xc146e29f87c1c123ULL), (0x53a202a6f1535351ULL),
            (0xdcae8ba572dcdc57ULL), (0x0b582716530b0b2cULL), (0x9d9cd327019d9d4eULL), (0x6c47c1d82b6c6cadULL),
            (0x3195f562a43131c4ULL), (0x7487b9e8f37474cdULL), (0xf6e309f115f6f6ffULL), (0x460a438c4c464605ULL),
            (0xac092645a5acac8aULL), (0x893c970fb589891eULL), (0x14a04428b4141450ULL), (0xe15b42dfbae1e1a3ULL),
            (0x16b04e2ca6161658ULL), (0x3acdd274f73a3ae8ULL), (0x696fd0d2066969b9ULL), (0x09482d1241090924ULL),
            (0x70a7ade0d77070ddULL), (0xb6d954716fb6b6e2ULL), (0xd0ceb7bd1ed0d067ULL), (0xed3b7ec7d6eded93ULL),
            (0xcc2edb85e2cccc17ULL), (0x422a578468424215ULL), (0x98b4c22d2c98985aULL), (0xa4490e55eda4a4aaULL),
            (0x285d8850752828a0ULL), (0x5cda31b8865c5c6dULL), (0xf8933fed6bf8f8c7ULL), (0x8644a411c2868622ULL),
        },
        {
            /* C6 vectors */
            (0x6018c07830d81818ULL), (0x8c2305af46262323ULL), (0x3fc67ef991b8c6c6ULL), (0x87e8136fcdfbe8e8ULL),
            (0x26874ca113cb8787ULL), (0xdab8a9626d11b8b8ULL), (0x0401080502090101ULL), (0x214f426e9e0d4f4fULL),
            (0xd836adee6c9b3636ULL), (0xa2a6590451ffa6a6ULL), (0x6fd2debdb90cd2d2ULL), (0xf3f5fb06f70ef5f5ULL),
            (0xf979ef80f2967979ULL), (0xa16f5fcede306f6fULL), (0x7e91fcef3f6d9191ULL), (0x5552aa07a4f85252ULL),
            (0x9d6027fdc0476060ULL), (0xcabc89766535bcbcULL), (0x569baccd2b379b9bULL), (0x028e048c018a8e8eULL),
            (0xb6a371155bd2a3a3ULL), (0x300c603c186c0c0cULL), (0xf17bff8af6847b7bULL), (0xd435b5e16a803535ULL),
            (0x741de8693af51d1dULL), (0xa7e05347ddb3e0e0ULL), (0x7bd7f6acb321d7d7ULL), (0x2fc25eed999cc2c2ULL),
            (0xb82e6d965c432e2eULL), (0x314b627a96294b4bULL), (0xdffea321e15dfefeULL), (0x41578216aed55757ULL),
            (0x5415a8412abd1515ULL), (0xc1779fb6eee87777ULL), (0xdc37a5eb6e923737ULL), (0xb3e57b56d79ee5e5ULL),
            (0x469f8cd923139f9fULL), (0xe7f0d317fd23f0f0ULL), (0x354a6a7f94204a4aULL), (0x4fda9e95a944dadaULL),
            (0x7d58fa25b0a25858ULL), (0x03c906ca8fcfc9c9ULL), (0xa429558d527c2929ULL), (0x280a5022145a0a0aULL),
            (0xfeb1e14f7f50b1b1ULL), (0xbaa0691a5dc9a0a0ULL), (0xb16b7fdad6146b6bULL), (0x2e855cab17d98585ULL),
            (0xcebd8173673cbdbdULL), (0x695dd234ba8f5d5dULL), (0x4010805020901010ULL), (0xf7f4f303f507f4f4ULL),
            (0x0bcb16c08bddcbcbULL), (0xf83eedc67cd33e3eULL), (0x140528110a2d0505ULL), (0x81671fe6ce786767ULL),
            (0xb7e47353d597e4e4ULL), (0x9c2725bb4e022727ULL), (0x1941325882734141ULL), (0x168b2c9d0ba78b8bULL),
            (0xa6a7510153f6a7a7ULL), (0xe97dcf94fab27d7dULL), (0x6e95dcfb37499595ULL), (0x47d88e9fad56d8d8ULL),
            (0xcbfb8b30eb70fbfbULL), (0x9fee2371c1cdeeeeULL), (0xed7cc791f8bb7c7cULL), (0x856617e3cc716666ULL),
            (0x53dda68ea77bddddULL), (0x5c17b84b2eaf1717ULL), (0x014702468e454747ULL), (0x429e84dc211a9e9eULL),
            (0x0fca1ec589d4cacaULL), (0xb42d75995a582d2dULL), (0xc6bf9179632ebfbfULL), (0x1c07381b0e3f0707ULL),
            (0x8ead012347acadadULL), (0x755aea2fb4b05a5aULL), (0x36836cb51bef8383ULL), (0xcc3385ff66b63333ULL),
            (0x91633ff2c65c6363ULL), (0x0802100a04120202ULL), (0x92aa39384993aaaaULL), (0xd971afa8e2de7171ULL),
            (0x07c80ecf8dc6c8c8ULL), (0x6419c87d32d11919ULL), (0x39497270923b4949ULL), (0x43d9869aaf5fd9d9ULL),
            (0xeff2c31df931f2f2ULL), (0xabe34b48dba8e3e3ULL), (0x715be22ab6b95b5bULL), (0x1a8834920dbc8888ULL),
            (0x529aa4c8293e9a9aULL), (0x98262dbe4c0b2626ULL), (0xc8328dfa64bf3232ULL), (0xfab0e94a7d59b0b0ULL),
            (0x83e91b6acff2e9e9ULL), (0x3c0f78331e770f0fULL), (0x73d5e6a6b733d5d5ULL), (0x3a8074ba1df48080ULL),
            (0xc2be997c6127bebeULL), (0x13cd26de87ebcdcdULL), (0xd034bde468893434ULL), (0x3d487a7590324848ULL),
            (0xdbffab24e354ffffULL), (0xf57af78ff48d7a7aULL), (0x7a90f4ea3d649090ULL), (0x615fc23ebe9d5f5fULL),
            (0x80201da0403d2020ULL), (0xbd6867d5d00f6868ULL), (0x681ad07234ca1a1aULL), (0x82ae192c41b7aeaeULL),
            (0xeab4c95e757db4b4ULL), (0x4d549a19a8ce5454ULL), (0x7693ece53b7f9393ULL), (0x88220daa442f2222ULL),
            (0x8d6407e9c8636464ULL), (0xe3f1db12ff2af1f1ULL), (0xd173bfa2e6cc7373ULL), (0x4812905a24821212ULL),
            (0x1d403a5d807a4040ULL), (0x2008402810480808ULL), (0x2bc356e89b95c3c3ULL), (0x97ec337bc5dfececULL),
            (0x4bdb9690ab4ddbdbULL), (0xbea1611f5fc0a1a1ULL), (0x0e8d1c8307918d8dULL), (0xf43df5c97ac83d3dULL),
            (0x6697ccf1335b9797ULL), (0x0000000000000000ULL), (0x1bcf36d483f9cfcfULL), (0xac2b4587566e2b2bULL),
            (0xc57697b3ece17676ULL), (0x328264b019e68282ULL), (0x7fd6fea9b128d6d6ULL), (0x6c1bd87736c31b1bULL),
            (0xeeb5c15b7774b5b5ULL), (0x86af112943beafafULL), (0xb56a77dfd41d6a6aULL), (0x5d50ba0da0ea5050ULL),
            (0x0945124c8a574545ULL), (0xebf3cb18fb38f3f3ULL), (0xc0309df060ad3030ULL), (0x9bef2b74c3c4efefULL),
            (0xfc3fe5c37eda3f3fULL), (0x4955921caac75555ULL), (0xb2a2791059dba2a2ULL), (0x8fea0365c9e9eaeaULL),
            (0x89650fecca6a6565ULL), (0xd2bab9686903babaULL), (0xbc2f65935e4a2f2fULL), (0x27c04ee79d8ec0c0ULL),
            (0x5fdebe81a160dedeULL), (0x701ce06c38fc1c1cULL), (0xd3fdbb2ee746fdfdULL), (0x294d52649a1f4d4dULL),
            (0x7292e4e039769292ULL), (0xc9758fbceafa7575ULL), (0x1806301e0c360606ULL), (0x128a249809ae8a8aULL),
            (0xf2b2f940794bb2b2ULL), (0xbfe66359d185e6e6ULL), (0x380e70361c7e0e0eULL), (0x7c1ff8633ee71f1fULL),
            (0x956237f7c4556262ULL), (0x77d4eea3b53ad4d4ULL), (0x9aa829324d81a8a8ULL), (0x6296c4f431529696ULL),
            (0xc3f99b3aef62f9f9ULL), (0x33c566f697a3c5c5ULL), (0x942535b14a102525ULL), (0x7959f220b2ab5959ULL),
            (0x2a8454ae15d08484ULL), (0xd572b7a7e4c57272ULL), (0xe439d5dd72ec3939ULL), (0x2d4c5a6198164c4cULL),
            (0x655eca3bbc945e5eULL), (0xfd78e785f09f7878ULL), (0xe038ddd870e53838ULL), (0x0a8c148605988c8cULL),
            (0x63d1c6b2bf17d1d1ULL), (0xaea5410b57e4a5a5ULL), (0xafe2434dd9a1e2e2ULL), (0x99612ff8c24e6161ULL),
            (0xf6b3f1457b42b3b3ULL), (0x842115a542342121ULL), (0x4a9c94d625089c9cULL), (0x781ef0663cee1e1eULL),
            (0x1143225286614343ULL), (0x3bc776fc93b1c7c7ULL), (0xd7fcb32be54ffcfcULL), (0x1004201408240404ULL),
            (0x5951b208a2e35151ULL), (0x5e99bcc72f259999ULL), (0xa96d4fc4da226d6dULL), (0x340d68391a650d0dULL),
            (0xcffa8335e979fafaULL), (0x5bdfb684a369dfdfULL), (0xe57ed79bfca97e7eULL), (0x90243db448192424ULL),
            (0xec3bc5d776fe3b3bULL), (0x96ab313d4b9aababULL), (0x1fce3ed181f0ceceULL), (0x4411885522991111ULL),
            (0x068f0c8903838f8fULL), (0x254e4a6b9c044e4eULL), (0xe6b7d1517366b7b7ULL), (0x8beb0b60cbe0ebebULL),
            (0xf03cfdcc78c13c3cULL), (0x3e817cbf1ffd8181ULL), (0x6a94d4fe35409494ULL), (0xfbf7eb0cf31cf7f7ULL),
            (0xdeb9a1676f18b9b9ULL), (0x4c13985f268b1313ULL), (0xb02c7d9c58512c2cULL), (0x6bd3d6b8bb05d3d3ULL),
            (0xbbe76b5cd38ce7e7ULL), (0xa56e57cbdc396e6eULL), (0x37c46ef395aac4c4ULL), (0x0c03180f061b0303ULL),
            (0x45568a13acdc5656ULL), (0x0d441a49885e4444ULL), (0xe17fdf9efea07f7fULL), (0x9ea921374f88a9a9ULL),
            (0xa82a4d8254672a2aULL), (0xd6bbb16d6b0abbbbULL), (0x23c146e29f87c1c1ULL), (0x5153a202a6f15353ULL),
            (0x57dcae8ba572dcdcULL), (0x2c0b582716530b0bULL), (0x4e9d9cd327019d9dULL), (0xad6c47c1d82b6c6cULL),
            (0xc43195f562a43131ULL), (0xcd7487b9e8f37474ULL), (0xfff6e309f115f6f6ULL), (0x05460a438c4c4646ULL),
            (0x8aac092645a5acacULL), (0x1e893c970fb58989ULL), (0x5014a04428b41414ULL), (0xa3e15b42dfbae1e1ULL),
            (0x5816b04e2ca61616ULL), (0xe83acdd274f73a3aULL), (0xb9696fd0d2066969ULL), (0x2409482d12410909ULL),
            (0xdd70a7ade0d77070ULL), (0xe2b6d954716fb6b6ULL), (0x67d0ceb7bd1ed0d0ULL), (0x93ed3b7ec7d6ededULL),
            (0x17cc2edb85e2ccccULL), (0x15422a5784684242ULL), (0x5a98b4c22d2c9898ULL), (0xaaa4490e55eda4a4ULL),
            (0xa0285d8850752828ULL), (0x6d5cda31b8865c5cULL), (0xc7f8933fed6bf8f8ULL), (0x228644a411c28686ULL),
        },
        {
            /* C7 vectors */
            (0x186018c07830d818ULL), (0x238c2305af462623ULL), (0xc63fc67ef991b8c6ULL), (0xe887e8136fcdfbe8ULL),
            (0x8726874ca113cb87ULL), (0xb8dab8a9626d11b8ULL), (0x0104010805020901ULL), (0x4f214f426e9e0d4fULL),
            (0x36d836adee6c9b36ULL), (0xa6a2a6590451ffa6ULL), (0xd26fd2debdb90cd2ULL), (0xf5f3f5fb06f70ef5ULL),
            (0x79f979ef80f29679ULL), (0x6fa16f5fcede306fULL), (0x917e91fcef3f6d91ULL), (0x525552aa07a4f852ULL),
            (0x609d6027fdc04760ULL), (0xbccabc89766535bcULL), (0x9b569baccd2b379bULL), (0x8e028e048c018a8eULL),
            (0xa3b6a371155bd2a3ULL), (0x0c300c603c186c0cULL), (0x7bf17bff8af6847bULL), (0x35d435b5e16a8035ULL),
            (0x1d741de8693af51dULL), (0xe0a7e05347ddb3e0ULL), (0xd77bd7f6acb321d7ULL), (0xc22fc25eed999cc2ULL),
            (0x2eb82e6d965c432eULL), (0x4b314b627a96294bULL), (0xfedffea321e15dfeULL), (0x5741578216aed557ULL),
            (0x155415a8412abd15ULL), (0x77c1779fb6eee877ULL), (0x37dc37a5eb6e9237ULL), (0xe5b3e57b56d79ee5ULL),
            (0x9f469f8cd923139fULL), (0xf0e7f0d317fd23f0ULL), (0x4a354a6a7f94204aULL), (0xda4fda9e95a944daULL),
            (0x587d58fa25b0a258ULL), (0xc903c906ca8fcfc9ULL), (0x29a429558d527c29ULL), (0x0a280a5022145a0aULL),
            (0xb1feb1e14f7f50b1ULL), (0xa0baa0691a5dc9a0ULL), (0x6bb16b7fdad6146bULL), (0x852e855cab17d985ULL),
            (0xbdcebd8173673cbdULL), (0x5d695dd234ba8f5dULL), (0x1040108050209010ULL), (0xf4f7f4f303f507f4ULL),
            (0xcb0bcb16c08bddcbULL), (0x3ef83eedc67cd33eULL), (0x05140528110a2d05ULL), (0x6781671fe6ce7867ULL),
            (0xe4b7e47353d597e4ULL), (0x279c2725bb4e0227ULL), (0x4119413258827341ULL), (0x8b168b2c9d0ba78bULL),
            (0xa7a6a7510153f6a7ULL), (0x7de97dcf94fab27dULL), (0x956e95dcfb374995ULL), (0xd847d88e9fad56d8ULL),
            (0xfbcbfb8b30eb70fbULL), (0xee9fee2371c1cdeeULL), (0x7ced7cc791f8bb7cULL), (0x66856617e3cc7166ULL),
            (0xdd53dda68ea77bddULL), (0x175c17b84b2eaf17ULL), (0x47014702468e4547ULL), (0x9e429e84dc211a9eULL),
            (0xca0fca1ec589d4caULL), (0x2db42d75995a582dULL), (0xbfc6bf9179632ebfULL), (0x071c07381b0e3f07ULL),
            (0xad8ead012347acadULL), (0x5a755aea2fb4b05aULL), (0x8336836cb51bef83ULL), (0x33cc3385ff66b633ULL),
            (0x6391633ff2c65c63ULL), (0x020802100a041202ULL), (0xaa92aa39384993aaULL), (0x71d971afa8e2de71ULL),
            (0xc807c80ecf8dc6c8ULL), (0x196419c87d32d119ULL), (0x4939497270923b49ULL), (0xd943d9869aaf5fd9ULL),
            (0xf2eff2c31df931f2ULL), (0xe3abe34b48dba8e3ULL), (0x5b715be22ab6b95bULL), (0x881a8834920dbc88ULL),
            (0x9a529aa4c8293e9aULL), (0x2698262dbe4c0b26ULL), (0x32c8328dfa64bf32ULL), (0xb0fab0e94a7d59b0ULL),
            (0xe983e91b6acff2e9ULL), (0x0f3c0f78331e770fULL), (0xd573d5e6a6b733d5ULL), (0x803a8074ba1df480ULL),
            (0xbec2be997c6127beULL), (0xcd13cd26de87ebcdULL), (0x34d034bde4688934ULL), (0x483d487a75903248ULL),
            (0xffdbffab24e354ffULL), (0x7af57af78ff48d7aULL), (0x907a90f4ea3d6490ULL), (0x5f615fc23ebe9d5fULL),
            (0x2080201da0403d20ULL), (0x68bd6867d5d00f68ULL), (0x1a681ad07234ca1aULL), (0xae82ae192c41b7aeULL),
            (0xb4eab4c95e757db4ULL), (0x544d549a19a8ce54ULL), (0x937693ece53b7f93ULL), (0x2288220daa442f22ULL),
            (0x648d6407e9c86364ULL), (0xf1e3f1db12ff2af1ULL), (0x73d173bfa2e6cc73ULL), (0x124812905a248212ULL),
            (0x401d403a5d807a40ULL), (0x0820084028104808ULL), (0xc32bc356e89b95c3ULL), (0xec97ec337bc5dfecULL),
            (0xdb4bdb9690ab4ddbULL), (0xa1bea1611f5fc0a1ULL), (0x8d0e8d1c8307918dULL), (0x3df43df5c97ac83dULL),
            (0x976697ccf1335b97ULL), (0x0000000000000000ULL), (0xcf1bcf36d483f9cfULL), (0x2bac2b4587566e2bULL),
            (0x76c57697b3ece176ULL), (0x82328264b019e682ULL), (0xd67fd6fea9b128d6ULL), (0x1b6c1bd87736c31bULL),
            (0xb5eeb5c15b7774b5ULL), (0xaf86af112943beafULL), (0x6ab56a77dfd41d6aULL), (0x505d50ba0da0ea50ULL),
            (0x450945124c8a5745ULL), (0xf3ebf3cb18fb38f3ULL), (0x30c0309df060ad30ULL), (0xef9bef2b74c3c4efULL),
            (0x3ffc3fe5c37eda3fULL), (0x554955921caac755ULL), (0xa2b2a2791059dba2ULL), (0xea8fea0365c9e9eaULL),
            (0x6589650fecca6a65ULL), (0xbad2bab9686903baULL), (0x2fbc2f65935e4a2fULL), (0xc027c04ee79d8ec0ULL),
            (0xde5fdebe81a160deULL), (0x1c701ce06c38fc1cULL), (0xfdd3fdbb2ee746fdULL), (0x4d294d52649a1f4dULL),
            (0x927292e4e0397692ULL), (0x75c9758fbceafa75ULL), (0x061806301e0c3606ULL), (0x8a128a249809ae8aULL),
            (0xb2f2b2f940794bb2ULL), (0xe6bfe66359d185e6ULL), (0x0e380e70361c7e0eULL), (0x1f7c1ff8633ee71fULL),
            (0x62956237f7c45562ULL), (0xd477d4eea3b53ad4ULL), (0xa89aa829324d81a8ULL), (0x966296c4f4315296ULL),
            (0xf9c3f99b3aef62f9ULL), (0xc533c566f697a3c5ULL), (0x25942535b14a1025ULL), (0x597959f220b2ab59ULL),
            (0x842a8454ae15d084ULL), (0x72d572b7a7e4c572ULL), (0x39e439d5dd72ec39ULL), (0x4c2d4c5a6198164cULL),
            (0x5e655eca3bbc945eULL), (0x78fd78e785f09f78ULL), (0x38e038ddd870e538ULL), (0x8c0a8c148605988cULL),
            (0xd163d1c6b2bf17d1ULL), (0xa5aea5410b57e4a5ULL), (0xe2afe2434dd9a1e2ULL), (0x6199612ff8c24e61ULL),
            (0xb3f6b3f1457b42b3ULL), (0x21842115a5423421ULL), (0x9c4a9c94d625089cULL), (0x1e781ef0663cee1eULL),
            (0x4311432252866143ULL), (0xc73bc776fc93b1c7ULL), (0xfcd7fcb32be54ffcULL), (0x0410042014082404ULL),
            (0x515951b208a2e351ULL), (0x995e99bcc72f2599ULL), (0x6da96d4fc4da226dULL), (0x0d340d68391a650dULL),
            (0xfacffa8335e979faULL), (0xdf5bdfb684a369dfULL), (0x7ee57ed79bfca97eULL), (0x2490243db4481924ULL),
            (0x3bec3bc5d776fe3bULL), (0xab96ab313d4b9aabULL), (0xce1fce3ed181f0ceULL), (0x1144118855229911ULL),
            (0x8f068f0c8903838fULL), (0x4e254e4a6b9c044eULL), (0xb7e6b7d1517366b7ULL), (0xeb8beb0b60cbe0ebULL),
            (0x3cf03cfdcc78c13cULL), (0x813e817cbf1ffd81ULL), (0x946a94d4fe354094ULL), (0xf7fbf7eb0cf31cf7ULL),
            (0xb9deb9a1676f18b9ULL), (0x134c13985f268b13ULL), (0x2cb02c7d9c58512cULL), (0xd36bd3d6b8bb05d3ULL),
            (0xe7bbe76b5cd38ce7ULL), (0x6ea56e57cbdc396eULL), (0xc437c46ef395aac4ULL), (0x030c03180f061b03ULL),
            (0x5645568a13acdc56ULL), (0x440d441a49885e44ULL), (0x7fe17fdf9efea07fULL), (0xa99ea921374f88a9ULL),
            (0x2aa82a4d8254672aULL), (0xbbd6bbb16d6b0abbULL), (0xc123c146e29f87c1ULL), (0x535153a202a6f153ULL),
            (0xdc57dcae8ba572dcULL), (0x0b2c0b582716530bULL), (0x9d4e9d9cd327019dULL), (0x6cad6c47c1d82b6cULL),
            (0x31c43195f562a431ULL), (0x74cd7487b9e8f374ULL), (0xf6fff6e309f115f6ULL), (0x4605460a438c4c46ULL),
            (0xac8aac092645a5acULL), (0x891e893c970fb589ULL), (0x145014a04428b414ULL), (0xe1a3e15b42dfbae1ULL),
            (0x165816b04e2ca616ULL), (0x3ae83acdd274f73aULL), (0x69b9696fd0d20669ULL), (0x092409482d124109ULL),
            (0x70dd70a7ade0d770ULL), (0xb6e2b6d954716fb6ULL), (0xd067d0ceb7bd1ed0ULL), (0xed93ed3b7ec7d6edULL),
            (0xcc17cc2edb85e2ccULL), (0x4215422a57846842ULL), (0x985a98b4c22d2c98ULL), (0xa4aaa4490e55eda4ULL),
            (0x28a0285d88507528ULL), (0x5c6d5cda31b8865cULL), (0xf8c7f8933fed6bf8ULL), (0x86228644a411c286ULL),
        } };

struct context {
  context()
  {
    std::memset(message, 0x0, 64 * sizeof(u8));
    std::memset(hash, 0x0, 8 * sizeof(u64));
    length = 0;
  }
  context(const context &) = default;
  context(context &&) = default;
  ~context()
  {
    // for security
    std::memset(message, 0x0, 64 * sizeof(u8));
    std::memset(hash, 0x0, 8 * sizeof(u64));
    length = 0;
  }
  u8 message[blck_sz];
  u64 hash[digest_sz];
  size_t length;
};
template <size_t S, typename T>
inline __attribute__((always_inline)) u64
whirlpool_op(const T &src)
{
  return (whirlpool_sbox[0][static_cast<i32>(src[S & 7] >> 56)]
          ^ whirlpool_sbox[1][static_cast<i32>(src[(S + 7) & 7] >> 48) & 0xFF]
          ^ whirlpool_sbox[2][static_cast<i32>(src[(S + 6) & 7] >> 40) & 0xFF]
          ^ whirlpool_sbox[3][static_cast<i32>(src[(S + 5) & 7] >> 32) & 0xFF]
          ^ whirlpool_sbox[4][static_cast<i32>(src[(S + 4) & 7] >> 24) & 0xFF]
          ^ whirlpool_sbox[5][static_cast<i32>(src[(S + 3) & 7] >> 16) & 0xFF]
          ^ whirlpool_sbox[6][static_cast<i32>(src[(S + 2) & 7] >> 8) & 0xFF]
          ^ whirlpool_sbox[7][static_cast<i32>(src[(S + 1) & 7]) & 0xFF]);
}
// it's much easier to define this via the pp rather than inlining it, also compilers may not always include this
// correctly
#define whirlpool_buffer_load(x)                                                                                        \
  key[0][x] = hash[x];                                                                                                  \
  state[0][x] = __builtin_bswap64(block[x]) ^ hash[x];                                                                  \
  hash[x] = state[0][x];

// since 1/10 iteration of the function
template <size_t N, typename K, typename S>
inline __attribute__((always_inline)) void
whirlpool_iteration(K &&key, S &&state, u32 &flag)
{
  key[flag ^ 1][0] = whirlpool_op<0>(key[flag]) ^ whirl_rc[N];
  key[flag ^ 1][1] = whirlpool_op<1>(key[flag]);
  key[flag ^ 1][2] = whirlpool_op<2>(key[flag]);
  key[flag ^ 1][3] = whirlpool_op<3>(key[flag]);
  key[flag ^ 1][4] = whirlpool_op<4>(key[flag]);
  key[flag ^ 1][5] = whirlpool_op<5>(key[flag]);
  key[flag ^ 1][6] = whirlpool_op<6>(key[flag]);
  key[flag ^ 1][7] = whirlpool_op<7>(key[flag]);

  state[flag ^ 1][0] = whirlpool_op<0>(state[flag]) ^ key[flag ^ 1][0];
  state[flag ^ 1][1] = whirlpool_op<1>(state[flag]) ^ key[flag ^ 1][1];
  state[flag ^ 1][2] = whirlpool_op<2>(state[flag]) ^ key[flag ^ 1][2];
  state[flag ^ 1][3] = whirlpool_op<3>(state[flag]) ^ key[flag ^ 1][3];
  state[flag ^ 1][4] = whirlpool_op<4>(state[flag]) ^ key[flag ^ 1][4];
  state[flag ^ 1][5] = whirlpool_op<5>(state[flag]) ^ key[flag ^ 1][5];
  state[flag ^ 1][6] = whirlpool_op<6>(state[flag]) ^ key[flag ^ 1][6];
  state[flag ^ 1][7] = whirlpool_op<7>(state[flag]) ^ key[flag ^ 1][7];

  flag = flag ^ 1;
}

inline void
whirlpool_round(u64 *__restrict hash, const u64 *__restrict block)
{
  u64 key[2][8] = {};
  u64 state[2][8] = {};

  // all loops have been manually unrolled
  u32 flag = 0;
  whirlpool_buffer_load(0);
  whirlpool_buffer_load(1);
  whirlpool_buffer_load(2);
  whirlpool_buffer_load(3);
  whirlpool_buffer_load(4);
  whirlpool_buffer_load(5);
  whirlpool_buffer_load(6);
  whirlpool_buffer_load(7);
  whirlpool_iteration<0>(key, state, flag);
  whirlpool_iteration<1>(key, state, flag);
  whirlpool_iteration<2>(key, state, flag);
  whirlpool_iteration<3>(key, state, flag);
  whirlpool_iteration<4>(key, state, flag);
  whirlpool_iteration<5>(key, state, flag);
  whirlpool_iteration<6>(key, state, flag);
  whirlpool_iteration<7>(key, state, flag);
  whirlpool_iteration<8>(key, state, flag);
  whirlpool_iteration<9>(key, state, flag);
  // Miyaguchi-Preneel compression function
  hash[0] ^= state[0][0];
  hash[1] ^= state[0][1];
  hash[2] ^= state[0][2];
  hash[3] ^= state[0][3];
  hash[4] ^= state[0][4];
  hash[5] ^= state[0][5];
  hash[6] ^= state[0][6];
  hash[7] ^= state[0][7];
}
void
whirlpool_update(context &ctx, const u8 *msg, size_t size)
{
  unsigned index = (unsigned)ctx.length & 63;
  unsigned left;
  ctx.length += size;

  /* fill partial block */
  if ( index ) {
    left = blck_sz - index;
    std::memcpy(ctx.message + index, msg, (size < left ? size : left));
    if ( size < left )
      return;

    /* process partial block */
    whirlpool_round(ctx.hash, reinterpret_cast<u64 *>(ctx.message));
    msg += left;
    size -= left;
  }
  while ( size >= blck_sz ) {
    const u64 *aligned_message_block;
    if ( aligned(msg) ) {
      /* the most common case is processing of an already aligned message
      without copying it */
      aligned_message_block = reinterpret_cast<const u64 *>(msg);
    } else {
      std::memcpy(ctx.message, msg, blck_sz);
      aligned_message_block = reinterpret_cast<const u64 *>(ctx.message);
    }

    whirlpool_round(ctx.hash, aligned_message_block);
    msg += blck_sz;
    size -= blck_sz;
  }
  if ( size ) {
    /* save leftovers */
    std::memcpy(ctx.message, msg, size);
  }
}

u64 *
whirlpool_pad(u64 length, u8 *__restrict message, u64 *__restrict hash)
{
  unsigned index = (unsigned)length & 63;
  u64 *msg64 = reinterpret_cast<u64 *>(message);
  message[index++] = 0x80;

  if ( index > 32 ) {
    while ( index < 64 ) {
      message[index++] = 0;
    }
    whirlpool_round(hash, msg64);
    index = 0;
  }
  while ( index < 56 ) {
    message[index++] = 0;
  }
  msg64[7] = __builtin_bswap64(length << 3);
  return msg64;
}

void
whirlpool_final(context &ctx)
{
  whirlpool_round(ctx.hash, whirlpool_pad(ctx.length, ctx.message, ctx.hash));
}

typedef std::array<u64, digest_sz> wbuffer;

inline wbuffer
__whirlpool(const u8 *data)
{
  size_t sz = std::strlen(reinterpret_cast<const char *>(data));     // no idea why they don't have overloads for this :(
  context ctx;
  std::memset(ctx.message, 0x0, 64 * sizeof(u8));
  std::memset(ctx.hash, 0x0, 8 * sizeof(u64));
  ctx.length = 0;
  whirlpool_update(ctx, const_cast<u8 *>(data), sz);
  whirlpool_final(ctx);
  wbuffer bf;
  std::memcpy(&bf[0], ctx.hash, 8 * sizeof(u64));
  return bf;
}

inline wbuffer
__whirlpool(const char *data)
{
  size_t sz = std::strlen(data);
  context ctx;
  std::memset(ctx.message, 0x0, 64 * sizeof(u8));
  std::memset(ctx.hash, 0x0, 8 * sizeof(u64));
  ctx.length = 0;
  whirlpool_update(ctx, const_cast<u8 *>(reinterpret_cast<const u8 *>(data)), sz);
  whirlpool_final(ctx);
  wbuffer bf;
  std::memcpy(&bf[0], ctx.hash, 8 * sizeof(u64));
  return bf;
}

template <stl_container T>
inline wbuffer
__whirlpool(const T &data)
{
  context ctx;
  std::memset(ctx.message, 0x0, 64 * sizeof(u8));
  std::memset(ctx.hash, 0x0, 8 * sizeof(u64));
  ctx.length = 0;
  whirlpool_update(ctx, const_cast<u8 *>(reinterpret_cast<const u8 *>(data.data())), data.size());
  whirlpool_final(ctx);
  wbuffer bf;
  std::memcpy(&bf[0], ctx.hash, 8 * sizeof(u64));
  return bf;
}

};
// the functions you should call to hash data, anything above is reserved for the implementation only
auto
whirlpool(const char *data) -> whrlpl::wbuffer
{
  return whrlpl::__whirlpool(data);
}
template <typename T>
  requires std::is_fundamental_v<T>
auto
whirlpool(const T *data) -> whrlpl::wbuffer
{
  return whrlpl::__whirlpool(reinterpret_cast<whrlpl::u8 *>(data));
}
// adapts to all contiguous STL containers
template <whrlpl::stl_container T>
auto
whirlpool(T &data) -> whrlpl::wbuffer
{
  return whrlpl::__whirlpool(data);
}

template <whrlpl::stl_container T>
auto
whirlpool(const T &data) -> whrlpl::wbuffer
{
  return whrlpl::__whirlpool(data);
}
