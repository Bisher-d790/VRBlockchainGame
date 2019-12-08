pragma solidity ^0.4.25;


import "./weaponFactory.sol";
contract weaponHelper is weaponFactory {

  uint levelUpFee = 0.001 ether;
  
   modifier onlyOwnerOf(uint _weaponId) {
    require(msg.sender == WeaponToOwner[_weaponId]);
    _;
  }

  modifier aboveLevel(uint _level, uint _weaponId) {
    require(weapons[_weaponId].level >= _level);
    _;
  }

  function withdraw() external onlyOwner {
    address _owner = owner();
    _owner.transfer(address(this).balance);
  }

  function setLevelUpFee(uint _fee) external onlyOwner {
    levelUpFee = _fee;
  }

  function levelUp(uint _weaponId) external payable {
    require(msg.value == levelUpFee);
    weapons[_weaponId].level = weapons[_weaponId].level.add(1);
  }

  function changeName(uint _weaponId, string _newName) external aboveLevel(2, _weaponId) onlyOwnerOf(_weaponId) {
    weapons[_weaponId].name = _newName;
  }

  function changeCreds(uint _weaponId, uint _newCreds) external aboveLevel(20, _weaponId) onlyOwnerOf(_weaponId) {
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
}
