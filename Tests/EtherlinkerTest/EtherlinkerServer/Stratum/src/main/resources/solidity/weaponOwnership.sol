pragma solidity ^0.4.25;


import "./erc721.sol";
import "./safemath.sol";
import "./weaponHelper.sol";

contract weaponOwnership is weaponHelper {

  using SafeMath for uint256;

  mapping (uint => address) weaponApprovals;

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
}
