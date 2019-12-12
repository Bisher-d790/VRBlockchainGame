package com.academy.contracts;

import io.reactivex.Flowable;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import org.web3j.abi.EventEncoder;
import org.web3j.abi.TypeReference;
import org.web3j.abi.datatypes.Address;
import org.web3j.abi.datatypes.Bool;
import org.web3j.abi.datatypes.Event;
import org.web3j.abi.datatypes.Function;
import org.web3j.abi.datatypes.Type;
import org.web3j.abi.datatypes.Utf8String;
import org.web3j.abi.datatypes.generated.Bytes32;
import org.web3j.abi.datatypes.generated.Uint256;
import org.web3j.crypto.Credentials;
import org.web3j.protocol.Web3j;
import org.web3j.protocol.core.DefaultBlockParameter;
import org.web3j.protocol.core.RemoteCall;
import org.web3j.protocol.core.methods.request.EthFilter;
import org.web3j.protocol.core.methods.response.Log;
import org.web3j.protocol.core.methods.response.TransactionReceipt;
import org.web3j.tx.Contract;
import org.web3j.tx.TransactionManager;
import org.web3j.tx.gas.ContractGasProvider;

/**
 * <p>Auto generated code.
 * <p><strong>Do not modify!</strong>
 * <p>Please use the <a href="https://docs.web3j.io/command_line.html">web3j command line tools</a>,
 * or the org.web3j.codegen.SolidityFunctionWrapperGenerator in the 
 * <a href="https://github.com/web3j/web3j/tree/master/codegen">codegen module</a> to update.
 *
 * <p>Generated with web3j version 4.1.0.
 */
public class PremiumSubscriptionToken extends Contract {
    private static final String BINARY = "608060405260038054600160a060020a03191633179055611a58806100256000396000f3006080604052600436106101535763ffffffff7c0100000000000000000000000000000000000000000000000000000000600035041663095ea7b381146101585780631420ee221461018e57806318160ddd146101b05780631c1c641d146101d257806323b872dd146101f257806327de2f8d1461021257806331ecad6614610232578063395093511461025257806342966c681461027257806366951e391461029257806370a08231146102b2578063715018a6146102d257806379cc6790146102e75780638da5cb5b146103075780639201de551461032957806394e8767d14610356578063a457c2d714610376578063a4faf09f14610396578063a9059cbb146103b6578063acabdf75146103d6578063cd055531146103f6578063dd62ed3e14610416578063e2cee85e14610436578063e939567914610456578063f2a90b4b14610476578063f2fde38b14610496575b600080fd5b34801561016457600080fd5b50610178610173366004611724565b6104b6565b604051610185919061195f565b60405180910390f35b34801561019a57600080fd5b506101ae6101a9366004611786565b610527565b005b3480156101bc57600080fd5b506101c56105d5565b604051610185919061196d565b3480156101de57600080fd5b506101c56101ed366004611838565b6105db565b3480156101fe57600080fd5b5061017861020d3660046116d7565b6105f0565b34801561021e57600080fd5b5061017861022d366004611724565b6106aa565b34801561023e57600080fd5b506101ae61024d366004611838565b610823565b34801561025e57600080fd5b5061017861026d366004611724565b61088c565b34801561027e57600080fd5b506101ae61028d366004611838565b61091d565b34801561029e57600080fd5b506101ae6102ad3660046117c8565b61092a565b3480156102be57600080fd5b506101c56102cd36600461167f565b610a37565b3480156102de57600080fd5b506101ae610a52565b3480156102f357600080fd5b506101ae610302366004611724565b610ac0565b34801561031357600080fd5b5061031c610ace565b6040516101859190611951565b34801561033557600080fd5b50610349610344366004611838565b610add565b604051610185919061197b565b34801561036257600080fd5b506101c5610371366004611838565b610c53565b34801561038257600080fd5b50610178610391366004611724565b610cb1565b3480156103a257600080fd5b506101ae6103b1366004611856565b610cfc565b3480156103c257600080fd5b506101786103d1366004611724565b610d86565b3480156103e257600080fd5b506101ae6103f13660046117c8565b610d9c565b34801561040257600080fd5b506101ae610411366004611754565b610ea1565b34801561042257600080fd5b506101c561043136600461169d565b611057565b34801561044257600080fd5b506101ae610451366004611856565b611082565b34801561046257600080fd5b50610349610471366004611838565b611289565b34801561048257600080fd5b506101ae610491366004611856565b611297565b3480156104a257600080fd5b506101ae6104b136600461167f565b611314565b6000600160a060020a03831615156104cd57600080fd5b336000818152600160209081526040808320600160a060020a03881680855292529182902085905590519091906000805160206119ff8339815191529061051590869061196d565b60405180910390a35060015b92915050565b600354600090600160a060020a0316331461054157600080fd5b5060005b818110156105d0576005600084848481811061055d57fe5b602090810292909201358352508101919091526040016000908120818155600101557fa51c5188e1948c771c5869a9d2c919518028dc8e3c947dd22fd3ae13aeda4c4a8383838181106105ac57fe5b905060200201356040516105c0919061196d565b60405180910390a1600101610545565b505050565b60025490565b60009081526005602052604090206001015490565b600160a060020a0383166000908152600160209081526040808320338452909152812054610624908363ffffffff61133416565b600160a060020a038516600090815260016020908152604080832033845290915290205561065384848461134b565b600160a060020a0384166000818152600160209081526040808320338085529252918290205491519092916000805160206119ff83398151915291610698919061196d565b60405180910390a35060019392505050565b60006060836106b884611289565b6040516020018083600160a060020a0316600160a060020a03166c0100000000000000000000000002815260140182805190602001908083835b602083106107115780518252601f1990920191602091820191016106f2565b6001836020036101000a0380198251168184511680821785525050505050509050019250505060405160208183030381529060405290506004816040518082805190602001908083835b6020831061077a5780518252601f19909201916020918201910161075b565b51815160209384036101000a6000190180199092169116179052920194855250604051938490030190922054421080159250905061081b57506004816040518082805190602001908083835b602083106107e55780518252601f1990920191602091820191016107c6565b51815160209384036101000a60001901801990921691161790529201948552506040519384900301909220600101544211159150505b949350505050565b600354600160a060020a0316331461083a57600080fd5b60008181526005602052604080822082815560010191909155517fa51c5188e1948c771c5869a9d2c919518028dc8e3c947dd22fd3ae13aeda4c4a9061088190839061196d565b60405180910390a150565b6000600160a060020a03831615156108a357600080fd5b336000908152600160209081526040808320600160a060020a03871684529091529020546108d7908363ffffffff61141d16565b336000818152600160209081526040808320600160a060020a038916808552925291829020849055905190926000805160206119ff83398151915291610515919061196d565b6109273382611436565b50565b6000610934611607565b600354600160a060020a0316331461094b57600080fd5b84831461095757600080fd5b600091505b84821015610a2f57604080518082019091528087878581811061097b57fe5b905060200201358152602001858585818110151561099557fe5b905060200201358152509050806005600088888681811015156109b457fe5b6020908102929092013583525081810192909252604001600020825181559101516001909101557f2bf5da1e90f7b3234642edd1283811b71e4130202f7f9024b5b260ae536af5df868684818110610a0857fe5b90506020020135604051610a1c919061196d565b60405180910390a160019091019061095c565b505050505050565b600160a060020a031660009081526020819052604090205490565b600354600160a060020a03163314610a6957600080fd5b600354604051600160a060020a03909116907ff8df31144d9c2f0f6b59d69b8b98abd5459d07f2742c4df920b25aae33c6482090600090a26003805473ffffffffffffffffffffffffffffffffffffffff19169055565b610aca82826114e2565b5050565b600354600160a060020a031681565b6040805160208082528183019092526060918291600091829182918591908082016104008038833901905050945060009350600092505b6020831015610ba1576008830260020a870291507fff00000000000000000000000000000000000000000000000000000000000000821615610b9657818585815181101515610b5f57fe5b9060200101907effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1916908160001a9053506001909301925b600190920191610b14565b836040519080825280601f01601f191660200182016040528015610bcf578160200160208202803883390190505b509050600092505b83831015610c49578483815181101515610bed57fe5b90602001015160f860020a900460f860020a028184815181101515610c0e57fe5b9060200101907effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1916908160001a905350600190920191610bd7565b9695505050505050565b6000811515610c8357507f3000000000000000000000000000000000000000000000000000000000000000610cac565b6000821115610cac5761010081049050600a820660300160f860020a0217600a82049150610c83565b919050565b6000600160a060020a0383161515610cc857600080fd5b336000908152600160209081526040808320600160a060020a03871684529091529020546108d7908363ffffffff61133416565b610d04611607565b600354600160a060020a03163314610d1b57600080fd5b506040805180820182528381526020808201848152600086815260059092529083902082518155905160019091015590517f2bf5da1e90f7b3234642edd1283811b71e4130202f7f9024b5b260ae536af5df90610d7990859061196d565b60405180910390a1505050565b6000610d9333848461134b565b50600192915050565b6000610da6611607565b600354600160a060020a03163314610dbd57600080fd5b848314610dc957600080fd5b600091505b84821015610a2f576040805180820190915280878785818110610ded57fe5b9050602002013581526020018585858181101515610e0757fe5b90506020020135815250905080600560008888868181101515610e2657fe5b6020908102929092013583525081810192909252604001600020825181559101516001909101557f99e5fc2422da5e949a914149894c1b8cb972a4edec220e66c58a5968a668dc0d868684818110610e7a57fe5b90506020020135604051610e8e919061196d565b60405180910390a1600190910190610dce565b610ea9611607565b600354606090600160a060020a03163314610ec357600080fd5b6000838152600560205260409020541515610edd57600080fd5b610ee785846106aa565b15610f27576040517f08c379a0000000000000000000000000000000000000000000000000000000008152600401610f1e9061198c565b60405180910390fd5b6040805180820190915242808252620151808602016020820152915084610f4d84611289565b6040516020018083600160a060020a0316600160a060020a03166c0100000000000000000000000002815260140182805190602001908083835b60208310610fa65780518252601f199092019160209182019101610f87565b6001836020036101000a038019825116818451168082178552505050505050905001925050506040516020818303038152906040529050816004826040518082805190602001908083835b602083106110105780518252601f199092019160209182019101610ff1565b51815160209384036101000a600019018019909216911617905292019485525060405193849003810190932084518155939092015160019093019290925550505050505050565b600160a060020a03918216600090815260016020908152604080832093909416825291909152205490565b61108a611607565b60008281526005602052604090205460609015156110a757600080fd5b60008381526005602052604090206001015484026110c433610a37565b10156110fc576040517f08c379a0000000000000000000000000000000000000000000000000000000008152600401610f1e9061199c565b61110633846106aa565b1561113d576040517f08c379a0000000000000000000000000000000000000000000000000000000008152600401610f1e9061198c565b60008381526005602052604090206001015461115a90850261091d565b604080518082019091524280825262015180860201602082015291503361118084611289565b6040516020018083600160a060020a0316600160a060020a03166c0100000000000000000000000002815260140182805190602001908083835b602083106111d95780518252601f1990920191602091820191016111ba565b6001836020036101000a038019825116818451168082178552505050505050905001925050506040516020818303038152906040529050816004826040518082805190602001908083835b602083106112435780518252601f199092019160209182019101611224565b51815160209384036101000a6000190180199092169116179052920194855250604051938490038101909320845181559390920151600190930192909255505050505050565b606061052161034483610c53565b61129f611607565b600354600160a060020a031633146112b657600080fd5b506040805180820182528381526020808201848152600086815260059092529083902082518155905160019091015590517f99e5fc2422da5e949a914149894c1b8cb972a4edec220e66c58a5968a668dc0d90610d7990859061196d565b600354600160a060020a0316331461132b57600080fd5b61092781611589565b6000808383111561134457600080fd5b5050900390565b600160a060020a038216151561136057600080fd5b600160a060020a038316600090815260208190526040902054611389908263ffffffff61133416565b600160a060020a0380851660009081526020819052604080822093909355908416815220546113be908263ffffffff61141d16565b600160a060020a0380841660008181526020819052604090819020939093559151908516907fddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef9061141090859061196d565b60405180910390a3505050565b60008282018381101561142f57600080fd5b9392505050565b600160a060020a038216151561144b57600080fd5b60025461145e908263ffffffff61133416565b600255600160a060020a03821660009081526020819052604090205461148a908263ffffffff61133416565b600160a060020a0383166000818152602081905260408082209390935591517fddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef906114d690859061196d565b60405180910390a35050565b600160a060020a0382166000908152600160209081526040808320338452909152902054611516908263ffffffff61133416565b600160a060020a03831660009081526001602090815260408083203384529091529020556115448282611436565b600160a060020a0382166000818152600160209081526040808320338085529252918290205491519092916000805160206119ff833981519152916114d6919061196d565b600160a060020a038116151561159e57600080fd5b600354604051600160a060020a038084169216907f8be0079c531659141344cd1fd0a4f28419497f9722a3daafe3b4186f6b6457e090600090a36003805473ffffffffffffffffffffffffffffffffffffffff1916600160a060020a0392909216919091179055565b604080518082019091526000808252602082015290565b600061142f82356119b0565b600080601f8301841361163c57600080fd5b50813567ffffffffffffffff81111561165457600080fd5b60208301915083602082028301111561166c57600080fd5b9250929050565b600061142f82356119c1565b60006020828403121561169157600080fd5b600061081b848461161e565b600080604083850312156116b057600080fd5b60006116bc858561161e565b92505060206116cd8582860161161e565b9150509250929050565b6000806000606084860312156116ec57600080fd5b60006116f8868661161e565b93505060206117098682870161161e565b925050604061171a86828701611673565b9150509250925092565b6000806040838503121561173757600080fd5b6000611743858561161e565b92505060206116cd85828601611673565b60008060006060848603121561176957600080fd5b6000611775868661161e565b935050602061170986828701611673565b6000806020838503121561179957600080fd5b823567ffffffffffffffff8111156117b057600080fd5b6117bc8582860161162a565b92509250509250929050565b600080600080604085870312156117de57600080fd5b843567ffffffffffffffff8111156117f557600080fd5b6118018782880161162a565b9450945050602085013567ffffffffffffffff81111561182057600080fd5b61182c8782880161162a565b95989497509550505050565b60006020828403121561184a57600080fd5b600061081b8484611673565b6000806040838503121561186957600080fd5b60006117438585611673565b61187e816119b0565b82525050565b61187e816119bc565b61187e816119c1565b60006118a1826119ac565b8084526118b58160208601602086016119c4565b6118be816119f4565b9093016020019392505050565b602b81527f4572726f723a207072656d69756d20737562736372697074696f6e206973207360208201527f74696c6c20616374697665000000000000000000000000000000000000000000604082015260600190565b601981527f4572726f723a20696e73756666696369656e742066756e647300000000000000602082015260400190565b602081016105218284611875565b602081016105218284611884565b60208101610521828461188d565b6020808252810161142f8184611896565b60208082528101610521816118cb565b6020808252810161052181611921565b5190565b600160a060020a031690565b151590565b90565b60005b838110156119df5781810151838201526020016119c7565b838111156119ee576000848401525b50505050565b601f01601f19169056008c5be1e5ebec7d5bd14f71427d1e84f3dd0314c0f7b2291e5b200ac8c7c3b925a265627a7a7230582098e2c1c11c20bff26486cd164c1b9ee4b1c00a15e65f27c5face3799a98723486c6578706572696d656e74616cf50037";

    public static final String FUNC_APPROVE = "approve";

    public static final String FUNC_BATCHDELETEPREMIUMSUBSCRIPTIONTYPES = "batchDeletePremiumSubscriptionTypes";

    public static final String FUNC_TOTALSUPPLY = "totalSupply";

    public static final String FUNC_GETPREMIUMSUBSCRIPTIONPRICEPERDAY = "getPremiumSubscriptionPricePerDay";

    public static final String FUNC_TRANSFERFROM = "transferFrom";

    public static final String FUNC_CHECKPREMIUMSUBSCRIPTION = "checkPremiumSubscription";

    public static final String FUNC_DELETEPREMIUMSUBSCRIPTIONTYPE = "deletePremiumSubscriptionType";

    public static final String FUNC_INCREASEALLOWANCE = "increaseAllowance";

    public static final String FUNC_BURN = "burn";

    public static final String FUNC_BATCHADDPREMIUMSUBSCRIPTIONTYPES = "batchAddPremiumSubscriptionTypes";

    public static final String FUNC_BALANCEOF = "balanceOf";

    public static final String FUNC_RENOUNCEOWNERSHIP = "renounceOwnership";

    public static final String FUNC_BURNFROM = "burnFrom";

    public static final String FUNC_OWNER = "owner";

    public static final String FUNC_BYTES32TOSTRING = "bytes32ToString";

    public static final String FUNC_UINTTOBYTES = "uintToBytes";

    public static final String FUNC_DECREASEALLOWANCE = "decreaseAllowance";

    public static final String FUNC_ADDPREMIUMSUBSCRIPTIONTYPE = "addPremiumSubscriptionType";

    public static final String FUNC_TRANSFER = "transfer";

    public static final String FUNC_BATCHEDITPREMIUMSUBSCRIPTIONTYPES = "batchEditPremiumSubscriptionTypes";

    public static final String FUNC_GRANTPREMIUMSUBSCRIPTION = "grantPremiumSubscription";

    public static final String FUNC_ALLOWANCE = "allowance";

    public static final String FUNC_BUYPREMIUMSUBSCRIPTION = "buyPremiumSubscription";

    public static final String FUNC_UINTTOSTRING = "uintToString";

    public static final String FUNC_EDITPREMIUMSUBSCRIPTIONTYPE = "editPremiumSubscriptionType";

    public static final String FUNC_TRANSFEROWNERSHIP = "transferOwnership";

    public static final Event ADDPREMIUMSUBSCRIPTIONTYPEEVENT_EVENT = new Event("AddPremiumSubscriptionTypeEvent", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Uint256>() {}));
    ;

    public static final Event EDITPREMIUMSUBSCRIPTIONTYPEEVENT_EVENT = new Event("EditPremiumSubscriptionTypeEvent", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Uint256>() {}));
    ;

    public static final Event DELETEPREMIUMSUBSCRIPTIONTYPEEVENT_EVENT = new Event("DeletePremiumSubscriptionTypeEvent", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Uint256>() {}));
    ;

    public static final Event OWNERSHIPRENOUNCED_EVENT = new Event("OwnershipRenounced", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Address>(true) {}));
    ;

    public static final Event OWNERSHIPTRANSFERRED_EVENT = new Event("OwnershipTransferred", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Address>(true) {}, new TypeReference<Address>(true) {}));
    ;

    public static final Event TRANSFER_EVENT = new Event("Transfer", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Address>(true) {}, new TypeReference<Address>(true) {}, new TypeReference<Uint256>() {}));
    ;

    public static final Event APPROVAL_EVENT = new Event("Approval", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Address>(true) {}, new TypeReference<Address>(true) {}, new TypeReference<Uint256>() {}));
    ;

    @Deprecated
    protected PremiumSubscriptionToken(String contractAddress, Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        super(BINARY, contractAddress, web3j, credentials, gasPrice, gasLimit);
    }

    protected PremiumSubscriptionToken(String contractAddress, Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        super(BINARY, contractAddress, web3j, credentials, contractGasProvider);
    }

    @Deprecated
    protected PremiumSubscriptionToken(String contractAddress, Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        super(BINARY, contractAddress, web3j, transactionManager, gasPrice, gasLimit);
    }

    protected PremiumSubscriptionToken(String contractAddress, Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        super(BINARY, contractAddress, web3j, transactionManager, contractGasProvider);
    }

    public RemoteCall<TransactionReceipt> approve(String spender, BigInteger value) {
        final Function function = new Function(
                FUNC_APPROVE, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(spender), 
                new org.web3j.abi.datatypes.generated.Uint256(value)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> batchDeletePremiumSubscriptionTypes(List<BigInteger> _premiumSubscriptionTypeIds) {
        final Function function = new Function(
                FUNC_BATCHDELETEPREMIUMSUBSCRIPTIONTYPES, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.DynamicArray<org.web3j.abi.datatypes.generated.Uint256>(
                        org.web3j.abi.Utils.typeMap(_premiumSubscriptionTypeIds, org.web3j.abi.datatypes.generated.Uint256.class))), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<BigInteger> totalSupply() {
        final Function function = new Function(FUNC_TOTALSUPPLY, 
                Arrays.<Type>asList(), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Uint256>() {}));
        return executeRemoteCallSingleValueReturn(function, BigInteger.class);
    }

    public RemoteCall<BigInteger> getPremiumSubscriptionPricePerDay(BigInteger _premiumSubscriptionTypeId) {
        final Function function = new Function(FUNC_GETPREMIUMSUBSCRIPTIONPRICEPERDAY, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_premiumSubscriptionTypeId)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Uint256>() {}));
        return executeRemoteCallSingleValueReturn(function, BigInteger.class);
    }

    public RemoteCall<TransactionReceipt> transferFrom(String from, String to, BigInteger value) {
        final Function function = new Function(
                FUNC_TRANSFERFROM, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(from), 
                new org.web3j.abi.datatypes.Address(to), 
                new org.web3j.abi.datatypes.generated.Uint256(value)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<Boolean> checkPremiumSubscription(String _user, BigInteger _premiumSubscriptionTypeId) {
        final Function function = new Function(FUNC_CHECKPREMIUMSUBSCRIPTION, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(_user), 
                new org.web3j.abi.datatypes.generated.Uint256(_premiumSubscriptionTypeId)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Bool>() {}));
        return executeRemoteCallSingleValueReturn(function, Boolean.class);
    }

    public RemoteCall<TransactionReceipt> deletePremiumSubscriptionType(BigInteger _premiumSubscriptionTypeId) {
        final Function function = new Function(
                FUNC_DELETEPREMIUMSUBSCRIPTIONTYPE, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_premiumSubscriptionTypeId)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> increaseAllowance(String spender, BigInteger addedValue) {
        final Function function = new Function(
                FUNC_INCREASEALLOWANCE, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(spender), 
                new org.web3j.abi.datatypes.generated.Uint256(addedValue)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> burn(BigInteger value) {
        final Function function = new Function(
                FUNC_BURN, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(value)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> batchAddPremiumSubscriptionTypes(List<BigInteger> _premiumSubscriptionTypeIds, List<BigInteger> _premiumSubscriptionPricesPerDay) {
        final Function function = new Function(
                FUNC_BATCHADDPREMIUMSUBSCRIPTIONTYPES, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.DynamicArray<org.web3j.abi.datatypes.generated.Uint256>(
                        org.web3j.abi.Utils.typeMap(_premiumSubscriptionTypeIds, org.web3j.abi.datatypes.generated.Uint256.class)), 
                new org.web3j.abi.datatypes.DynamicArray<org.web3j.abi.datatypes.generated.Uint256>(
                        org.web3j.abi.Utils.typeMap(_premiumSubscriptionPricesPerDay, org.web3j.abi.datatypes.generated.Uint256.class))), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<BigInteger> balanceOf(String owner) {
        final Function function = new Function(FUNC_BALANCEOF, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(owner)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Uint256>() {}));
        return executeRemoteCallSingleValueReturn(function, BigInteger.class);
    }

    public RemoteCall<TransactionReceipt> renounceOwnership() {
        final Function function = new Function(
                FUNC_RENOUNCEOWNERSHIP, 
                Arrays.<Type>asList(), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> burnFrom(String from, BigInteger value) {
        final Function function = new Function(
                FUNC_BURNFROM, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(from), 
                new org.web3j.abi.datatypes.generated.Uint256(value)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<String> owner() {
        final Function function = new Function(FUNC_OWNER, 
                Arrays.<Type>asList(), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Address>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    public RemoteCall<String> bytes32ToString(byte[] x) {
        final Function function = new Function(FUNC_BYTES32TOSTRING, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Bytes32(x)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Utf8String>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    public RemoteCall<byte[]> uintToBytes(BigInteger v) {
        final Function function = new Function(FUNC_UINTTOBYTES, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(v)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Bytes32>() {}));
        return executeRemoteCallSingleValueReturn(function, byte[].class);
    }

    public RemoteCall<TransactionReceipt> decreaseAllowance(String spender, BigInteger subtractedValue) {
        final Function function = new Function(
                FUNC_DECREASEALLOWANCE, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(spender), 
                new org.web3j.abi.datatypes.generated.Uint256(subtractedValue)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> addPremiumSubscriptionType(BigInteger _premiumSubscriptionTypeId, BigInteger _premiumSubscriptionPricePerDay) {
        final Function function = new Function(
                FUNC_ADDPREMIUMSUBSCRIPTIONTYPE, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_premiumSubscriptionTypeId), 
                new org.web3j.abi.datatypes.generated.Uint256(_premiumSubscriptionPricePerDay)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> transfer(String to, BigInteger value) {
        final Function function = new Function(
                FUNC_TRANSFER, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(to), 
                new org.web3j.abi.datatypes.generated.Uint256(value)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> batchEditPremiumSubscriptionTypes(List<BigInteger> _premiumSubscriptionTypeIds, List<BigInteger> _premiumSubscriptionPricesPerDay) {
        final Function function = new Function(
                FUNC_BATCHEDITPREMIUMSUBSCRIPTIONTYPES, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.DynamicArray<org.web3j.abi.datatypes.generated.Uint256>(
                        org.web3j.abi.Utils.typeMap(_premiumSubscriptionTypeIds, org.web3j.abi.datatypes.generated.Uint256.class)), 
                new org.web3j.abi.datatypes.DynamicArray<org.web3j.abi.datatypes.generated.Uint256>(
                        org.web3j.abi.Utils.typeMap(_premiumSubscriptionPricesPerDay, org.web3j.abi.datatypes.generated.Uint256.class))), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> grantPremiumSubscription(String _user, BigInteger _days, BigInteger _premiumSubscriptionTypeId) {
        final Function function = new Function(
                FUNC_GRANTPREMIUMSUBSCRIPTION, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(_user), 
                new org.web3j.abi.datatypes.generated.Uint256(_days), 
                new org.web3j.abi.datatypes.generated.Uint256(_premiumSubscriptionTypeId)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<BigInteger> allowance(String owner, String spender) {
        final Function function = new Function(FUNC_ALLOWANCE, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(owner), 
                new org.web3j.abi.datatypes.Address(spender)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Uint256>() {}));
        return executeRemoteCallSingleValueReturn(function, BigInteger.class);
    }

    public RemoteCall<TransactionReceipt> buyPremiumSubscription(BigInteger _days, BigInteger _premiumSubscriptionTypeId) {
        final Function function = new Function(
                FUNC_BUYPREMIUMSUBSCRIPTION, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_days), 
                new org.web3j.abi.datatypes.generated.Uint256(_premiumSubscriptionTypeId)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<String> uintToString(BigInteger v) {
        final Function function = new Function(FUNC_UINTTOSTRING, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(v)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Utf8String>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    public RemoteCall<TransactionReceipt> editPremiumSubscriptionType(BigInteger _premiumSubscriptionTypeId, BigInteger _premiumSubscriptionPricePerDay) {
        final Function function = new Function(
                FUNC_EDITPREMIUMSUBSCRIPTIONTYPE, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_premiumSubscriptionTypeId), 
                new org.web3j.abi.datatypes.generated.Uint256(_premiumSubscriptionPricePerDay)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> transferOwnership(String _newOwner) {
        final Function function = new Function(
                FUNC_TRANSFEROWNERSHIP, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(_newOwner)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public List<AddPremiumSubscriptionTypeEventEventResponse> getAddPremiumSubscriptionTypeEventEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(ADDPREMIUMSUBSCRIPTIONTYPEEVENT_EVENT, transactionReceipt);
        ArrayList<AddPremiumSubscriptionTypeEventEventResponse> responses = new ArrayList<AddPremiumSubscriptionTypeEventEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            AddPremiumSubscriptionTypeEventEventResponse typedResponse = new AddPremiumSubscriptionTypeEventEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse._premiumSubscriptionTypeId = (BigInteger) eventValues.getNonIndexedValues().get(0).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<AddPremiumSubscriptionTypeEventEventResponse> addPremiumSubscriptionTypeEventEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, AddPremiumSubscriptionTypeEventEventResponse>() {
            @Override
            public AddPremiumSubscriptionTypeEventEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(ADDPREMIUMSUBSCRIPTIONTYPEEVENT_EVENT, log);
                AddPremiumSubscriptionTypeEventEventResponse typedResponse = new AddPremiumSubscriptionTypeEventEventResponse();
                typedResponse.log = log;
                typedResponse._premiumSubscriptionTypeId = (BigInteger) eventValues.getNonIndexedValues().get(0).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<AddPremiumSubscriptionTypeEventEventResponse> addPremiumSubscriptionTypeEventEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(ADDPREMIUMSUBSCRIPTIONTYPEEVENT_EVENT));
        return addPremiumSubscriptionTypeEventEventFlowable(filter);
    }

    public List<EditPremiumSubscriptionTypeEventEventResponse> getEditPremiumSubscriptionTypeEventEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(EDITPREMIUMSUBSCRIPTIONTYPEEVENT_EVENT, transactionReceipt);
        ArrayList<EditPremiumSubscriptionTypeEventEventResponse> responses = new ArrayList<EditPremiumSubscriptionTypeEventEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            EditPremiumSubscriptionTypeEventEventResponse typedResponse = new EditPremiumSubscriptionTypeEventEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse._premiumSubscriptionTypeId = (BigInteger) eventValues.getNonIndexedValues().get(0).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<EditPremiumSubscriptionTypeEventEventResponse> editPremiumSubscriptionTypeEventEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, EditPremiumSubscriptionTypeEventEventResponse>() {
            @Override
            public EditPremiumSubscriptionTypeEventEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(EDITPREMIUMSUBSCRIPTIONTYPEEVENT_EVENT, log);
                EditPremiumSubscriptionTypeEventEventResponse typedResponse = new EditPremiumSubscriptionTypeEventEventResponse();
                typedResponse.log = log;
                typedResponse._premiumSubscriptionTypeId = (BigInteger) eventValues.getNonIndexedValues().get(0).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<EditPremiumSubscriptionTypeEventEventResponse> editPremiumSubscriptionTypeEventEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(EDITPREMIUMSUBSCRIPTIONTYPEEVENT_EVENT));
        return editPremiumSubscriptionTypeEventEventFlowable(filter);
    }

    public List<DeletePremiumSubscriptionTypeEventEventResponse> getDeletePremiumSubscriptionTypeEventEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(DELETEPREMIUMSUBSCRIPTIONTYPEEVENT_EVENT, transactionReceipt);
        ArrayList<DeletePremiumSubscriptionTypeEventEventResponse> responses = new ArrayList<DeletePremiumSubscriptionTypeEventEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            DeletePremiumSubscriptionTypeEventEventResponse typedResponse = new DeletePremiumSubscriptionTypeEventEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse._premiumSubscriptionTypeId = (BigInteger) eventValues.getNonIndexedValues().get(0).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<DeletePremiumSubscriptionTypeEventEventResponse> deletePremiumSubscriptionTypeEventEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, DeletePremiumSubscriptionTypeEventEventResponse>() {
            @Override
            public DeletePremiumSubscriptionTypeEventEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(DELETEPREMIUMSUBSCRIPTIONTYPEEVENT_EVENT, log);
                DeletePremiumSubscriptionTypeEventEventResponse typedResponse = new DeletePremiumSubscriptionTypeEventEventResponse();
                typedResponse.log = log;
                typedResponse._premiumSubscriptionTypeId = (BigInteger) eventValues.getNonIndexedValues().get(0).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<DeletePremiumSubscriptionTypeEventEventResponse> deletePremiumSubscriptionTypeEventEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(DELETEPREMIUMSUBSCRIPTIONTYPEEVENT_EVENT));
        return deletePremiumSubscriptionTypeEventEventFlowable(filter);
    }

    public List<OwnershipRenouncedEventResponse> getOwnershipRenouncedEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(OWNERSHIPRENOUNCED_EVENT, transactionReceipt);
        ArrayList<OwnershipRenouncedEventResponse> responses = new ArrayList<OwnershipRenouncedEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            OwnershipRenouncedEventResponse typedResponse = new OwnershipRenouncedEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse.previousOwner = (String) eventValues.getIndexedValues().get(0).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<OwnershipRenouncedEventResponse> ownershipRenouncedEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, OwnershipRenouncedEventResponse>() {
            @Override
            public OwnershipRenouncedEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(OWNERSHIPRENOUNCED_EVENT, log);
                OwnershipRenouncedEventResponse typedResponse = new OwnershipRenouncedEventResponse();
                typedResponse.log = log;
                typedResponse.previousOwner = (String) eventValues.getIndexedValues().get(0).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<OwnershipRenouncedEventResponse> ownershipRenouncedEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(OWNERSHIPRENOUNCED_EVENT));
        return ownershipRenouncedEventFlowable(filter);
    }

    public List<OwnershipTransferredEventResponse> getOwnershipTransferredEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(OWNERSHIPTRANSFERRED_EVENT, transactionReceipt);
        ArrayList<OwnershipTransferredEventResponse> responses = new ArrayList<OwnershipTransferredEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            OwnershipTransferredEventResponse typedResponse = new OwnershipTransferredEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse.previousOwner = (String) eventValues.getIndexedValues().get(0).getValue();
            typedResponse.newOwner = (String) eventValues.getIndexedValues().get(1).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<OwnershipTransferredEventResponse> ownershipTransferredEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, OwnershipTransferredEventResponse>() {
            @Override
            public OwnershipTransferredEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(OWNERSHIPTRANSFERRED_EVENT, log);
                OwnershipTransferredEventResponse typedResponse = new OwnershipTransferredEventResponse();
                typedResponse.log = log;
                typedResponse.previousOwner = (String) eventValues.getIndexedValues().get(0).getValue();
                typedResponse.newOwner = (String) eventValues.getIndexedValues().get(1).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<OwnershipTransferredEventResponse> ownershipTransferredEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(OWNERSHIPTRANSFERRED_EVENT));
        return ownershipTransferredEventFlowable(filter);
    }

    public List<TransferEventResponse> getTransferEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(TRANSFER_EVENT, transactionReceipt);
        ArrayList<TransferEventResponse> responses = new ArrayList<TransferEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            TransferEventResponse typedResponse = new TransferEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse.from = (String) eventValues.getIndexedValues().get(0).getValue();
            typedResponse.to = (String) eventValues.getIndexedValues().get(1).getValue();
            typedResponse.value = (BigInteger) eventValues.getNonIndexedValues().get(0).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<TransferEventResponse> transferEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, TransferEventResponse>() {
            @Override
            public TransferEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(TRANSFER_EVENT, log);
                TransferEventResponse typedResponse = new TransferEventResponse();
                typedResponse.log = log;
                typedResponse.from = (String) eventValues.getIndexedValues().get(0).getValue();
                typedResponse.to = (String) eventValues.getIndexedValues().get(1).getValue();
                typedResponse.value = (BigInteger) eventValues.getNonIndexedValues().get(0).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<TransferEventResponse> transferEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(TRANSFER_EVENT));
        return transferEventFlowable(filter);
    }

    public List<ApprovalEventResponse> getApprovalEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(APPROVAL_EVENT, transactionReceipt);
        ArrayList<ApprovalEventResponse> responses = new ArrayList<ApprovalEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            ApprovalEventResponse typedResponse = new ApprovalEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse.owner = (String) eventValues.getIndexedValues().get(0).getValue();
            typedResponse.spender = (String) eventValues.getIndexedValues().get(1).getValue();
            typedResponse.value = (BigInteger) eventValues.getNonIndexedValues().get(0).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<ApprovalEventResponse> approvalEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, ApprovalEventResponse>() {
            @Override
            public ApprovalEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(APPROVAL_EVENT, log);
                ApprovalEventResponse typedResponse = new ApprovalEventResponse();
                typedResponse.log = log;
                typedResponse.owner = (String) eventValues.getIndexedValues().get(0).getValue();
                typedResponse.spender = (String) eventValues.getIndexedValues().get(1).getValue();
                typedResponse.value = (BigInteger) eventValues.getNonIndexedValues().get(0).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<ApprovalEventResponse> approvalEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(APPROVAL_EVENT));
        return approvalEventFlowable(filter);
    }

    @Deprecated
    public static PremiumSubscriptionToken load(String contractAddress, Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        return new PremiumSubscriptionToken(contractAddress, web3j, credentials, gasPrice, gasLimit);
    }

    @Deprecated
    public static PremiumSubscriptionToken load(String contractAddress, Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        return new PremiumSubscriptionToken(contractAddress, web3j, transactionManager, gasPrice, gasLimit);
    }

    public static PremiumSubscriptionToken load(String contractAddress, Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        return new PremiumSubscriptionToken(contractAddress, web3j, credentials, contractGasProvider);
    }

    public static PremiumSubscriptionToken load(String contractAddress, Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        return new PremiumSubscriptionToken(contractAddress, web3j, transactionManager, contractGasProvider);
    }

    public static RemoteCall<PremiumSubscriptionToken> deploy(Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        return deployRemoteCall(PremiumSubscriptionToken.class, web3j, credentials, contractGasProvider, BINARY, "");
    }

    @Deprecated
    public static RemoteCall<PremiumSubscriptionToken> deploy(Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        return deployRemoteCall(PremiumSubscriptionToken.class, web3j, credentials, gasPrice, gasLimit, BINARY, "");
    }

    public static RemoteCall<PremiumSubscriptionToken> deploy(Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        return deployRemoteCall(PremiumSubscriptionToken.class, web3j, transactionManager, contractGasProvider, BINARY, "");
    }

    @Deprecated
    public static RemoteCall<PremiumSubscriptionToken> deploy(Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        return deployRemoteCall(PremiumSubscriptionToken.class, web3j, transactionManager, gasPrice, gasLimit, BINARY, "");
    }

    public static class AddPremiumSubscriptionTypeEventEventResponse {
        public Log log;

        public BigInteger _premiumSubscriptionTypeId;
    }

    public static class EditPremiumSubscriptionTypeEventEventResponse {
        public Log log;

        public BigInteger _premiumSubscriptionTypeId;
    }

    public static class DeletePremiumSubscriptionTypeEventEventResponse {
        public Log log;

        public BigInteger _premiumSubscriptionTypeId;
    }

    public static class OwnershipRenouncedEventResponse {
        public Log log;

        public String previousOwner;
    }

    public static class OwnershipTransferredEventResponse {
        public Log log;

        public String previousOwner;

        public String newOwner;
    }

    public static class TransferEventResponse {
        public Log log;

        public String from;

        public String to;

        public BigInteger value;
    }

    public static class ApprovalEventResponse {
        public Log log;

        public String owner;

        public String spender;

        public BigInteger value;
    }
}
