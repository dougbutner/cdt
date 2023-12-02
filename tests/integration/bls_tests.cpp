#include <boost/test/unit_test.hpp>
#include <eosio/testing/tester.hpp>
#include <eosio/chain/abi_serializer.hpp>

#include <fc/variant_object.hpp>

#include <contracts.hpp>

using namespace eosio;
using namespace eosio::testing;
using namespace eosio::chain;
using namespace eosio::testing;
using namespace fc;

using mvo = fc::mutable_variant_object;

struct bls_primitives_tester : tester {
   bls_primitives_tester() {
      create_accounts( { "test"_n } );
      produce_block();

      set_code( "eosio"_n,  contracts::bls_primitives_test_wasm() );
      set_abi(  "eosio"_n,  contracts::bls_primitives_test_abi().data() );

      produce_blocks();
   }
};

BOOST_AUTO_TEST_SUITE(bls_primitives_tests)

BOOST_FIXTURE_TEST_CASE( g1_add_test, bls_primitives_tester ) try {
   push_action("eosio"_n, "testg1add"_n, "test"_n, mvo()
      ("op1", "aa83970268d80b50a68535d920954bd993217b9114cbe255e5c0b64e748c5683b6518071552148ec555cdb8fed0f07001e76e62761e8d828a74b81f216a0c5ebeb923550cafd110512cec20e33ec9b272c0ff2b88215953945153fc926691506")
      ("op2", "e810c1d6ac7cbae0157a0fc958ef607c33e03dee20e72a97ae72de0dd9a0ef20d768ab4b659429255b87feda0be194062a77cd664976e6560b33c921d5968c19a5d5ae9e38c909690975c084c0a4e82481b01e4023b83d6a8ddcb9d38892f50f")
      ("res", "145cae227562a69bbf270b8ec8d1783bed4ad0fd43e9c81ac5caa7d3e7feaa3acda07d6033ece1f7f0649d6b75009a03e83ab8f9b44f94c4ab762611266b7a530ce05092ad38b7554a95caa2b63ad0969a902d69f34531dbccf8a4f2e12cf60d"));

} FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE( g2_add_test, bls_primitives_tester ) try {
   push_action("eosio"_n, "testg2add"_n, "test"_n, mvo()
      ("op1", "a75a447bc0dd806bcdaee2cb429498193e409a4d370dfe0e9605c5a9ec4a09c0314c0321f2f918b72e5f37cf10ea7e0b69ac1a7fb3200e63e5cef9929cd2d9afde2fb957989e610c5b44649af8649d968baa0424b873b501be32c66ef040240b469127753f17ca28a072c2151b69d51fecff1ed0f4786b4e6fd4e52ec72f95ef73cf19fc2d6a28267bdf11a262b403110c2e901fb32d0e900082e4934a20c1c06c262533488fd7f9f47e4e2fde102fe98fb48344de25712d5e2e2887bc04d207")
      ("op2", "11cc3115ad08c43ed0b7fc3945ca83c69d0a6663f05b25373ea3fdff14c722a7fddd7a1b4f1cf44290e1c480f50b6208419f6a208ea48a48cef5a345a35c052cf0db4a76c719eb90a5829a8f606e99c807a6ae71493f079c364d57f02cba7c124f344978bb539bea7c448eb96ccea9b6c7b7d2495212b88227fc269ac88391f4a6d23e2d47d4fe47e63f8e709b61450644ba13c08e29770bc397da41466cb26c9fa7a1ffd9b5dd5c51c3ddbfb88412998e41f72e63b7972dfd856b9f11530c01")
      ("res", "d9458632a7cfcf59e72cf6d1ad70ec8d65d9e81edd0da77c2b10ec4d2a4169f1b0ac46419796d3ed6ef66b34eb76651288d916a5e5b44e75cc849ecd257a223398f92683f2318bf5fe7aa2b5d45e97dad6c415dac4b9cdc1c72071a4c9845c15096b203deb2e071d3856983cb26a101eb193cbfe914000ade94a62339b2e418c4a53578fb177af1986cc9dee3ce9ff0f9598925cb7e5a29af31404fa8cd9c22e17eb1a44b6b461dd9b7dc4d384ad60b82d94e431a389a244b1724a5441ac6009"));

} FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE( g1_weighted_sum_test, bls_primitives_tester ) try {
   push_action("eosio"_n, "testg1wsum"_n, "test"_n, mvo()
      ("points", "7a63674c35f9f2be4f0ec092110b82fad24a283316a846d960843b9a6a8a98bfdabd7e897b7da774fbbb05d7ad95fb18940a5f7a7345e1821e0203e156d677e88445385bc0779d25f51b772be3c3a6ba0b09b2533a8ee66053b2f3c853994112e74a97324685e515c86d44ff5a3ef5218e53c6f29e7df49a546c79cd1fb9d14e63f68aaf6b2df1f6f56e6250fdd6f20dcc36499a5aea69f4c77a18774eccf8460e77ab6b0236ce2d85083faeacf0f3378a3dcc95e1d3b0ae282b9bbec1ecee1793e63ca4730ec63df496546c07094e848625610a514d99dd0a6dd9f58d15c4e4ed5aca65025562177ebd0a4c2c3ae8139d24be936dd5dbec6a54897ba2a98a68a9c43ea3199695896789c958bc289a7275550b5670a351b262c10166a48baa161f841df4255408abb7186f78647422313fbe3a0a35699a487dd71482b76b8adc20622f44bb32e04a78b98e4f2cd42f16a6d35ec2463a484906dbb655969b900a15cc8a47694b1961bd4b2e9f074afd79e4c04344d31dd8fcd56d5147a9a47712")
      ("scalars", "2be3984dc7a5c9e6172df42c905be929ce5bb29d9aa31a03f3ed8816e7d1265a0669a674fef9254f0efffd3e89c30f1f05587472251d362e1acea03a76918d137b322778b8188c1bf68c36ef8e0ce933290c67f981611c13a286e42235f89855e49966a4e9ad8c64122f4f5e720986193e59771fa91aef113d8739642bdd6613")
      ("num", 4)
      ("res", "25038aea2d2d1c15dad2fa4c6e31162d1b79ca1b1bca608190a05dea451701e9fc95a8c441a25083df7fa56d54eae51241a8c9489719b9cc35852ce3d7e04b5ada5c65f45d1818f80ea161264b70ab6fa86e694691281b8110000d209aea5c17"));

} FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE( g2_weighted_sum_test, bls_primitives_tester ) try {
   push_action("eosio"_n, "testg2wsum"_n, "test"_n, mvo()
      ("points", "556524e3e80fcf448c0befd659ad744c409cdd1111291a81949324a02688999ab88e6ccb3e9dcecf57ccfe9aa7ada21540ba5407c0700ce81578bcee892ed385dd1ed476c465fe48cea2dd7e37784d8ae795fba842ce0f88baa76857ec1c7c137163beed84ff2c6a159d486d10c7128b2cbb6f10c547d202d0f6e68fb43a9a6a18a01823c4e70b5dc25d38b9c33d4916510de467f10922f3b284855c4accc816f542fe74fd0b331b1884dac6918d3c38860b0725809a19b6101e5d3942b9f40eee6901e17a0c50187e6385767b7d1e54eaacbb3c1939e2e995ec79569dd0200583a937891035475e1e5a733a0446f7063e77f9d564c60dfc6dc25572369bf7fe51b2607f73fd0fa9eee9d27b127a81c63bbd7f08dd64237d082e9735018d96024c56d32b55e991e84f39c6ffc0d56ef17307e82fc200df9259f83b7bdae719124f7151d855b8f51f703e087ea1540900c4eba1592de051db895689aeb5233dec52ccb74f93acc8fc14bcde4413a14dceb0ec386623021ddf9ad1fce429e1780c5a6877b00b17af384fd49b7077434387672218967f4a7647174162c07e99d9007380be10a7bef367181ba886a0e40c160a4b36548826c30710ea8238b0c37ec06e331fe1d3aaf1b5a73ae0880794d0c0a9623b8498d9bbd4754e1a8c1e2346091fec42aaeddc40f2ae06456e8ad9059c61db437089a855af3d1bc2a6d68e9c01474bdbaabfa185a58dba9808f8e0b20a3c51c51c5bca629aa061dfa5ff238a43e1e90242df403635869743c723276c0eca711c6c91b94a65310b6b869ee556179ed113a2b406a52de2fe54f61f4589f510924b2e3f8b14ead1541af2e1cc9dd35a91f6cd4bbc02c58a844d9e4906a106197b8ab39a539561aeecd265762bcf5106344ae2fe0a62c7af1bbc846e9b39ebe38a046461d7c0c4901caddb0fd7c70b86246d53bf3124af629596f6367e86f3456cc954e3581bfea600b6d2818259332fedeb88ece673626ffd4d5935d0310e5cf2462055d5fa4b6cc4531f11cf0722c8647dbfc7364c9b2e24e0066ef5b0e3497ce38537a7230e02f7edc2f53e980f")
      ("scalars", "e5a6afde5d144ed43bd1742b7ec7f5385a7d392f65465927e37afe7b9f0a9e368449cf52e36ca432b096f8562c98f318216d21a426b2d51f0a4db8fcafcd687326b548cd973f30d4fc47d79d853ec94239c620229ea0632b2570a1f8df08fe1ce323ef2cad610917a13d1157e25fac05ef6bafaa68e8ce265594d207a5d13c1e")
      ("num", 4)
      ("res", "889d8b750987cbce4aa4b872b29f22011752354e672b24ad4b229ca575ce14a8c081366db5cfd0f7a85ff68559bd4216b3cecfb6a2618a29c6c95b17147d083f28cc1fae5959fd7de74d986e7fd543ce1060cbdd8d4ae136910d8a15a1b3ee16d955657630d5f50aae107d13aa0c46040616e2d3018e5d07f9551e2a4c34565c9b59b8fd7751e025f473772120b4a511946e09fc93dcf9732399244c1fbb864fa09c2dd5d29543e794e64b6e1a2df39289245ff4b65dff0357a6621d151e4514"));

} FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE( pairing_test, bls_primitives_tester ) try {
   push_action("eosio"_n, "testpairing"_n, "test"_n, mvo()
      ("g1_points", "af7d28fa69e9ff7cf98da7614f02faf91f8ae2888d522db1a225724394bedd8547ae93cb07b41f5f21092846c6c2950e43328c2e6aaa18cf735a703f4ee43a60658167b9c1bf895ddbc898dae5269a335699c595aa9dc4137103d5480320270f756a4c35700b847a02d4933be43e508139affb438b7bcf547debcf9904f1056d197ec8484283e2f194430e16443d250f0b4734d5380cac631d6287e2b45a6a12fb5fea3eed96a7b2cd3bac9a532e4bb6176b1e792964444798e5bf151e14c314277fa052e05911619c457335e708633aca11239a33686e56dd949e6f50e5fe79f1d069bbb01822566f992299184ddc06d08c662a5d2b37668c7821bef5177ff4df977799dc81ae15d0444be9a54db2195d41e316f7ebdb7d879f8f7b355cb416137401a36684f0ccbce51fd4d8b32f45d81f2c33bc95687ed777e7fcb181367e163d94356c96d239f193dabf01616d13936ba746ed9a64578a5a4b191238fe8472e4135525afcac4ed818c13e518864ce82de26a6bb1066b9c0771c021716603")
      ("g2_points", "5528fc322669dcf2757583835b5ba5cc84f629db47e1d5e3ec78523fff567ec26100b7977ba038586c9e465abbaeb603554afef9cfe21ac33847b1d11796088cc6b18c7544355da3f996ddb0c0a15c8b1eeba2ec3a5cc8c7b4a8ecc7131e4609582cc42caa57f68017f95af50757bfc0d3c4d4327d1d40012af8f664da428f1984bf17c26d43b6fd65a8ce6c3d039d03f1247385a3f565108de722d4e08b0e9d23bba036646668167bdd41709ebe8bf5aadbd88ccc2af0c6d5940531c9fd50053e786ffe9011554db15fc7e130ea07cd254f21a86911fe758517274f96b89cb67e30c104186c4a6cb0d92cb82e39260245b68e74bdb828992697a1957be0564a9863f56eaf36bb5fc4d0869468b6ad4e36a1e7c550303c80c4ca0cbae773b309a61c6d4d6a4d2f17a4424c1987d294f195275581c8b8f88b7ce7fec5bc67e7bfd58bb747f39aa4dbc77d79cd18dd09142b10a45d49abc8fd544281f02a0e045062b72b25ead1a376e4f705ac83ad2385c84a8fd914d2f6a71d7eeb7126d677001013a0df759ff906a09fe4a3da307dd6cc17ee1fd72af8f7d953662be427cda2985cb1073563bbea492d9e6a96ca8a05ca5d45d349cb3e2f09cff6022a9916324eaa4fe5c543d46cafe5f82e81c5baddc2cc58100b03a20c2feaeed58cbd63019b8e3586d14193470d4ee9c1a0fc5e0a736e1ba94d7ad20ead3a3dacc4b2f3530ad751daffa944be4cb1969b3d2595058007d28d49e2fdebab68607c119b77d766785ed9e209582c737fce93b6ad0d4d795f86415238e0d3b70b9d8954d6a20ce85e7128588a849c505d5d2c81ff63bf12ea3ad52a316316ce49b2014dfbc486c9934dccb98db06089c03dc8f76ad70323ada12fe7e5b9f552c5b6cc073f72409a6e44f6634ca58bed30649b9840f177ea0039932f81574ea22b6da18b702f0e367f633e41d2b585d5166669f4c48d389f003eeecf06b5aa119d0df46de26adcb938d362e4410fdaa990a6fc4c2eca0f7bffee724789a0a47ba1b531bb4a3c95c129585ba5c9a6fe978a6915f4afedeb710ef6a55f153a5b21f943de6531680d")
      ("res", "01cc207c7c76c65afc059d073106d545705af7c4e4ed78e6169c599bae1c9bf6358d5a2cdfeeae389cc64436dfe7b7192c733fe9e2d105c0eaec21589d8bb5ecd5c71a5fee083af47a1cbc3af2df8a13603a78956c39f55fd0663ed482846a047280f87426ecde4c535c0d30bdf4b95ff5aff45782129ee6c7a0fa20a632bc98e95bfb663685eb2443e4b1f518c40f00502303b3db49be61f36ef6af46b9097c83835a864ae6337ef07e40df617af1aacea98c0d75e96a104d41a3617e7a4f05fc1cdcec57ea40a0237ff387a5d9130b34c92cb57a3450080bbaa2f6f9e895851b05c05eec03abd2d5083c81c402a500d2bec4895cf0f58a9953e43ee9039a38ae73cc3ec325fa636777e1f597b69a2b6a62bd49fba5b163bc03ce73f277f818fad1c6681fa59be891c2baf85b6a5e908d96b6a6c4cf3d53b3de23fdade91b3dde7199648aca0fce1d2307253bf57b054a4c4dc276034f8d57017cddc0a84975c643f9ea808652f2cefea32f767fe8e6df58a837c47c3136ced7107e7dbd9711399605212e6a1b8da806a12636076f7da0629ca8173f0411ba2a1050d1bca61994e28f69f274ec94e016a3ba6f9a6b06cd17f570928b5e4b8c75a5d62a0a67bd54249702923b440355db775599ea7be7cd3c6d88ab8da7694e43352837b0080814880a1460bc61fae141d36f961db8393313f74a65c3eabcc38793b84062999364bb0c36a415445ec4318b59c16e850260a53e7aaaf72bcaa568b57b69b552bf827c3e1c116565122322d6c26e14354fd96dc4bb1161ede0ee36efeeae1a5503"));

} FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE( g1_map_test, bls_primitives_tester ) try {
   push_action("eosio"_n, "testg1map"_n, "test"_n, mvo()
      ("e", "6de1c03023f2b4e454559b97266ebc1f96cd5510c4f48e2acafbe73a536a1477f2c8d1c9b5f6615d01968ea59ef4fd07")
      ("res", "2c7390d4bfbe0ccbaae9699aab5458d62f6d1aa91938b0ab0717249ad89209cb14ee8ed764a8952415382dbbfdef2312d5b2988b1ed7e6907d73ef2335cba7f9263b63003effa44ab8d6805d6ed0f08d87919230f0cb45d9ec35b2e0615d920f"));

} FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE( g2_map_test, bls_primitives_tester ) try {
   push_action("eosio"_n, "testg2map"_n, "test"_n, mvo()
      ("e", "b4108d552274d175fd4e52dd766ff396a4f365c102e0ef7b4d266f220ec67eefab48ac15d1db0d98ba31cda435616e0bdeb51952b044ce0f64b5d42199d9560ed0175f3d2c58af07909d29db4480c1b417dfbf7f1af274648adb54b029e38f08")
      ("res", "f74a6a357dc6a1fb33344f60898ab9eb29c68170727136b26d943249fbbd9393bd893846ea0d43250d4fd37737e49f1463d11827561e80cda0f6ead2cd3c84d4be6d99d61fa4cbc41cce534af2cf3d1b3fc31ccecc1259cfc7530a93c58e801951454f38f693d2d763e0f993c202151d873eefec3e90507cea6232cb3c0061f254a2f4b5872098b23362763a79d6c004333e0e02ad077c8a3683d63827becf20c88a9b7a63bbac739bc3a4f659d119df2f5853e371a25c803fc8301c393e7804"));

} FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE( fp_mul_test, bls_primitives_tester ) try {
   push_action("eosio"_n, "testfpmul"_n, "test"_n, mvo()
      ("op1", "AAAAFFFFFFFFFEB9FFFF53B1FEFFAB1E24F6B0F6A0D23067BF1285F3844B7764D7AC4B43B6A71B4B9AE67F39EA11011A")
      ("op2", "AAAAFFFFFFFFFEB9FFFF53B1FEFFAB1E24F6B0F6A0D23067BF1285F3844B7764D7AC4B43B6A71B4B9AE67F39EA11011A")
      ("res", "010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));

} FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE( fp_exp_test, bls_primitives_tester ) try {
   push_action("eosio"_n, "testfpexp"_n, "test"_n, mvo()
      ("base", "AAAAFFFFFFFFFEB9FFFF53B1FEFFAB1E24F6B0F6A0D23067BF1285F3844B7764D7AC4B43B6A71B4B9AE67F39EA11011A")
      ("exp", "AAAAFFFFFFFFFEB9FFFF53B1FEFFAB1E24F6B0F6A0D23067BF1285F3844B7764D7AC4B43B6A71B4B9AE67F39EA11011A00000000000000000000000000000000")
      ("res", "010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));

} FC_LOG_AND_RETHROW()

BOOST_FIXTURE_TEST_CASE( sig_verify_test, bls_primitives_tester ) try {
   // assumes signed message of std::vector<uint8_t> msg = {51, 23, 56, 93, 212, 129, 128, 27, 251, 12, 42, 129, 210, 9, 34, 98};
   // vector<uint8_t> seed(32, 0x30); array<uint64_t, 4> sk = secret_key(seed); g1 pk = g1::one().scale(sk).affine(); string pk_hex = to_hex(pk.toAffineBytesLE());
   // g2 sig = sign(sk, msg); string sig_hex = to_hex(sig.toAffineBytesLE());
   push_action("eosio"_n, "verify"_n, "test"_n, mvo()
      ("pk", "c27efc440ed89d739ff80f1c7178d4672d5f71e8c8926a85785d0f84074e79c1662c522fdbd6fcaebd640d816dea6c0dc36c5d7e7a297afc960369e306d845fcad0e5fe2a88c0d3bbe854d4f9e3e6365c9c1003662f0e81b35fd9c6a11d0a10c")
      ("sig", "e13a38c18dfad440a9af8d720bfb9ce0f388a25a5789a8cdc34b87204fe29db5cc16658a5d9f4fa4a7cc16b8ef8d2d0d1a5984e6b69ca228692f1920e9340f149024b4d856711656f11bb1e0c7d081e5bb80692638a9bace2d8f4d796b4887129c59fbb7901997cbbb681f709291a45315979f55b719dfc8757d3a878cf01e4a48a0e6647b837d0ea8aea5d41e121b0dd37fa20007aef4f51740d846cc8d6ab151dbd88964e7d19890a500d5537be81b881451b75f928a66f546441d45028603"));

} FC_LOG_AND_RETHROW()

BOOST_AUTO_TEST_SUITE_END()
