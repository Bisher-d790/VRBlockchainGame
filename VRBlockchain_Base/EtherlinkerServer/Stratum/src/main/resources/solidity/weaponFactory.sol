pragma solidity ^0.4.25;


import "./safemath.sol";
//import "@openzeppelin/contracts/token/ERC721/ERC721Full.sol";
import "./erc721.sol";
import "./ownable.sol";

contract weaponFactory {

  using SafeMath for uint256;
  // 1. Declare using SafeMath32 for uint32
  using SafeMath32 for uint32;
  // 2. Declare using SafeMath16 for uint16
  using SafeMath16 for uint16;

  event NewWeapon(uint weaponId, string name, uint wepType);
  event Transfer(address indexed _from, address indexed _to, uint256 indexed _tokenId);
  event Approval(address indexed _owner, address indexed _approved, uint256 indexed _tokenId);
    
    function balanceOf(address _owner) external view returns (uint256) {
    return ownerWeaponCount[_owner];
  }

  function ownerOf(uint256 _tokenId) external view returns (address) {
    return WeaponToOwner[_tokenId];
  }

  function _transfer(address _from, address _to, uint256 _tokenId) private {
    ownerWeaponCount[_to] = ownerWeaponCount[_to].add(1);
    ownerWeaponCount[msg.sender] = ownerWeaponCount[msg.sender].sub(1);
    WeaponToOwner[_tokenId] = _to;
    emit Transfer(_from, _to, _tokenId); 
  }

  function transferFrom(address _from, address _to, uint256 _tokenId) external payable {
      require (WeaponToOwner[_tokenId] == msg.sender || weaponApprovals[_tokenId] == msg.sender);
      _transfer(_from, _to, _tokenId);
    }

  function approve(address _approved, uint256 _tokenId) external payable onlyOwnerOf(_tokenId) {
      weaponApprovals[_tokenId] = _approved;
      emit Approval(msg.sender, _approved, _tokenId);
    }
    
    

  uint wepTypeDigits = 16;
  uint wepTypeModulus = 10 ** wepTypeDigits;
  //uint cooldownTime = 1 days;

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
    _createWeapon(_name, _wepType);
  }
  
 

   function _createWeapon(string _name, uint8 _wepType) public returns(uint256) {
 
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
  
  uint levelUpFee = 0.001 ether;
  
   modifier onlyOwnerOf(uint _weaponId) {
    require(msg.sender == WeaponToOwner[_weaponId]);
    _;
  }

  modifier aboveLevel(uint _level, uint _weaponId) {
    require(weapons[_weaponId].level >= _level);
    _;
  }

 // function withdraw() external onlyOwnerOf {
 //   address _owner = owner();
 //   _owner.transfer(address(this).balance);
 // }

  //function setLevelUpFee(uint _fee) external onlyOwnerOf {
 //   levelUpFee = _fee;
 // }

  function levelUp(uint _weaponId) external payable {
    require(msg.value == levelUpFee);
    weapons[_weaponId].level = weapons[_weaponId].level.add(1);
    weapons[_weaponId].baseDamage = weapons[_weaponId].baseDamage.add(10);
    
  }

  function changeName(uint _weaponId, string _newName) external aboveLevel(2, _weaponId) onlyOwnerOf(_weaponId) {
    weapons[_weaponId].name = _newName;
  }

  function changeCreds(uint _weaponId, uint8 _newCreds) external aboveLevel(20, _weaponId) onlyOwnerOf(_weaponId) {
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
  
    mapping (uint => address) weaponApprovals;





  /*
  
     function mint(string _name, uint8 _wepType, address to, uint256 tokenId) public onlyOwner {
    require(to != address(0), "ERC721: mint to the zero address");
    _createWeapon(_name, _wepType);
    
  }
      function _mint(address to, uint256 tokenId) internal {
        require(to != address(0), "ERC721: mint to the zero address");
        require(!_exists(tokenId), "ERC721: token already minted");

        _tokenOwner[tokenId] = to;
        _ownedTokensCount[to].increment();

        emit Transfer(address(0), to, tokenId);
    }
 
  
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
