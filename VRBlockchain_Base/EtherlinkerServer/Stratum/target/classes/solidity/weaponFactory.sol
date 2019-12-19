pragma solidity ^0.4.25;


import "./safemath.sol";
//import "@openzeppelin/contracts/token/ERC721/ERC721Full.sol";
//import 'openzeppelin-solidity/contracts/token/ERC721/ERC721Token.sol';
//import "./erc721.sol";

contract weaponFactory {

 
    using SafeMath for uint256;
    using SafeMath32 for uint32;
    using SafeMath16 for uint16;
  
  //constructor() ERC721Token("WeaponFactory", "UNQWeapon") public {}
    //fire an event each time a new weapon is created.
  event NewWeapon(uint weaponId, string name, uint wepType);
  event Transfer(address indexed _from, address indexed _to, uint256 indexed _tokenId);
  event Approval(address indexed _owner, address indexed _approved, uint256 indexed _tokenId);

  uint wepTypeDigits = 16;
  uint levelUpFee = 0 ether;
  
  struct Weapon {
    string name;
    uint8 wepType;
    uint32 level;
    uint32 creationTime;
    uint256 baseDamage;
    uint16 winCount;
    uint16 lossCount;
  }

  Weapon[] public weapons;

  mapping (uint => address) public WeaponToOwner;
  mapping (address => uint) ownerWeaponCount;
  
  
  function _newPlayerCreate(string _name, uint8 _wepType) external {
    require(ownerWeaponCount[msg.sender] == 0);
    createWeapon(_name, _wepType);
  }

   function createWeapon(string _name, uint8 _wepType) public returns(uint256) {
 
    uint id = weapons.push(Weapon(_name, _wepType, 1, uint32(now), 20, 0, 0)) - 1;
    WeaponToOwner[id] = msg.sender;
    ownerWeaponCount[msg.sender] = ownerWeaponCount[msg.sender].add(1);
    emit NewWeapon(id, _name, _wepType);
    return id;
  }

  function getWeapon(uint256 _id) external view returns (
    string name,
    uint8 wepType,
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
  

  function getLevelUpFee() public view returns (uint) {
      return levelUpFee;
  }
  
   modifier onlyOwnerOf(uint _weaponId) {
    require(msg.sender == WeaponToOwner[_weaponId]);
    _;
  }

  modifier aboveLevel(uint _level, uint _weaponId) {
    require(weapons[_weaponId].level >= _level);
    _;
  }



  function levelUp(uint _weaponId) external  {
    //require(msg.value == levelUpFee);
    weapons[_weaponId].level = weapons[_weaponId].level.add(1);
    weapons[_weaponId].baseDamage = weapons[_weaponId].baseDamage.add(10);
    
  }

  function changeName(uint _weaponId, string _newName) external aboveLevel(1, _weaponId) onlyOwnerOf(_weaponId) {
    weapons[_weaponId].name = _newName;
  }

  function changeCreds(uint _weaponId, uint8 _newCreds) external aboveLevel(2, _weaponId) onlyOwnerOf(_weaponId) {
    weapons[_weaponId].wepType = _newCreds;
  }

  function getWeaponByOwner(address _owner) external view returns(uint[]) {
    uint[] memory result = new uint[](ownerWeaponCount[_owner]);
    uint counter = 0;
    for (uint i = 0; i < weapons.length; i++) {
      if (WeaponToOwner[i] == _owner) {
        result[counter] = i;
        counter++;
      }
    }
    return result;
  }
  
      function balanceOf(address _owner) external view returns (uint256) {
    return ownerWeaponCount[_owner];
  }

  function _ownerOf(uint256 _tokenId) external view returns (address) {
    return WeaponToOwner[_tokenId];
  }

  function _transfer(address _from, address _to, uint256 _tokenId) private {
    ownerWeaponCount[_to] = ownerWeaponCount[_to].add(1);
    ownerWeaponCount[msg.sender] = ownerWeaponCount[msg.sender].sub(1);
    WeaponToOwner[_tokenId] = _to;
    emit Transfer(_from, _to, _tokenId); 
  }

  function transferFrom(address _to, uint256 _tokenId) external  {
      require (WeaponToOwner[_tokenId] == msg.sender);
      _transfer(msg.sender, _to, _tokenId);
    }
    
  function burnn(uint256 _tokenId)  public {
    require (WeaponToOwner[_tokenId] == msg.sender);
    removeToken(msg.sender, _tokenId);
    emit Transfer(msg.sender, 0x0, _tokenId);
  }
  
function removeToken(address _from, uint256 _tokenId) private {
    //require(ownerOf(_tokenId) == _from);

    WeaponToOwner[_tokenId] = address(0x0);
    ownerWeaponCount[_from] = ownerWeaponCount[_from].sub(1);

  }

    mapping (uint => address) weaponApprovals;
    
}

