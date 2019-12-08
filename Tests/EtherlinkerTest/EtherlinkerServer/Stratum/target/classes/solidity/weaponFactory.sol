pragma solidity ^0.4.25;

import "./ownable.sol";
import "./safemath.sol";
import "./erc721.sol";


contract weaponFactory is Ownable, ERC721 {

  using SafeMath for uint256;
  // 1. Declare using SafeMath32 for uint32
  using SafeMath32 for uint32;
  // 2. Declare using SafeMath16 for uint16
  using SafeMath16 for uint16;

  event NewWeapon(uint weaponId, string name, uint wepType);

  uint wepTypeDigits = 16;
  uint wepTypeModulus = 10 ** wepTypeDigits;
  //uint cooldownTime = 1 days;

  struct Weapon {
    string name;
    uint wepType;
    uint32 level;
    uint32 creationTime;
    uint256 baseDamage;
    uint16 winCount;
    uint16 lossCount;
  }

  Weapon[] public weapons;

  mapping (uint => address) public WeaponToOwner;
  mapping (address => uint) ownerWeaponCount;

  function _createWeapon(string _name, uint _wepType) public onlyOwner {

    uint id = weapons.push(Weapon(_name, _wepType, 1, uint32(now), 20, 0, 0)) - 1;
    WeaponToOwner[id] = msg.sender;
    ownerWeaponCount[msg.sender] = ownerWeaponCount[msg.sender].add(1);
    emit NewWeapon(id, _name, _wepType);
  }

  function getWeapon(uint256 _id) external view returns (
    string name,
    uint wepType,
    uint32 level,
    uint32 creationTime,
    uint256 baseDamage,
    uint16 winCount,
    uint16 lossCount
  ) {
    Weapon memory _weapon = weapons[_id];
    name = _weapon.name;
    wepType = _weapon.wepType;
    level = _weapon.level;
    creationTime = _weapon.creationTime;
    baseDamage = _weapon.baseDamage;
    winCount = _weapon.winCount;
    lossCount = _weapon.lossCount;

  }




  /*
  --------------------------------------------------------------------------
    the below two functions might be byeond the scope of VR Blockchain game.


  // Used to generate a random weapon based on an inpurt string.
  function _generateRandomwepType(string _str) private view returns (uint) {
    uint rand = uint(keccak256(abi.encodePacked(_str)));
    return rand % wepTypeModulus;
  }

  // Can only be used by new users to generate a random weapon.
  function createRandomWeapon(string _name) public {
    require(ownerWeaponCount[msg.sender] == 0);
    uint randwepType = _generateRandomwepType(_name);
    randwepType = randwepType - randwepType % 100;
    _createWeapon(_name, randwepType);
  }
  //---------------------------------------------------------------------------

  */

}
